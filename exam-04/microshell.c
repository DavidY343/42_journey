#include <string.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdlib.h> 

void err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

// Function to handle the built-in 'cd' command.
int cd(char **argv, int i)
{
	// Check if the command has the correct number of arguments.
	if (i != 2)
		return err("error: cd: bad arguments\n"), 1;

	// Attempt to change the current directory to the one specified.
	if (chdir(argv[1]) == -1)
		return err("error: cd: cannot change directory to "), err(argv[1]), err("\n"), 1;

	return 0;
}

// Function to set up pipes for inter-process communication.
void set_pipe(int has_pipe, int *fd, int end)
{
	// If there is a pipe, duplicate the file descriptor for communication.
	if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		err("error: fatal\n"), exit(1); // Print error and exit if there's a failure.
}

// Function to execute a command with arguments.
int exec(char **argv, int i, char **envp)
{
	int has_pipe, fd[2], pid, status; // Declare variables for pipe state, file descriptors, and process control.
	has_pipe = argv[i] && !strcmp(argv[i], "|"); // Check if there is a pipe at the end of the command.

	// If the command is 'cd' and there's no pipe, call the cd function.
	if (!has_pipe && !strcmp(*argv, "cd"))
		return cd(argv, i);

	// If there's a pipe and creating it fails, print error and exit.
	if (has_pipe && pipe(fd) == -1)
		err("error: fatal\n"), exit(1);

	// Fork a new process to execute the command.
	if ((pid = fork()) == -1)
		err("error: fatal\n"), exit(1); // Print error and exit if fork fails.

	// In the child process (pid is 0).
	if (!pid)
	{
		argv[i] = 0; // Set the end of the arguments to NULL for execve.
		set_pipe(has_pipe, fd, 1); // Set up the pipe for writing.

		// If the command is 'cd', call the cd function and exit with its status.
		if (!strcmp(*argv, "cd"))
			exit(cd(argv, i));

		// Execute the command with execve.
		execve(*argv, argv, envp);
		// If execve fails, print an error message and exit.
		err("error: cannot execute "), err(*argv), err("\n"), exit(1);
	}

	// In the parent process, wait for the child to finish executing.
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, 0); // Close the pipe in the parent process.
	return WIFEXITED(status) && WEXITSTATUS(status); // Return the exit status of the child process.
}

// Main function: Entry point of the program.
int main(int argc, char **argv, char **envp)
{
	(void)argc; // Suppress unused variable warning for argc.
	int i = 0, status = 0; // Initialize index for argument parsing and status of last executed command.

	// Loop through the arguments until all are processed.
	while (argv[i])
	{
		argv += i + 1; // Move the argv pointer to the next command segment.
		i = 0; // Reset the index for the next command processing.

		// Loop to find the next command or pipe/semicolon.
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;

		// If a valid command segment was found, execute it.
		if (i)
			status = exec(argv, i, envp); // Execute the command and store the exit status.
	}

	return status; // Return the status of the last executed command.
}
