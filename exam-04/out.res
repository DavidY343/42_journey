/bin/ls
a.out
microshell
microshell.c
out.res
test.sh

/bin/cat microshell.c
#include <string.h>   // Include string handling functions, like strcmp.
#include <unistd.h>   // Include POSIX API for system calls like fork and chdir.
#include <sys/wait.h> // Include definitions for waiting on child processes.
#include <stdlib.h>   // Include standard library for general utility functions.

void err(char *str)
{
    // Function to write an error message to standard error (fd 2).
	while (*str)  // Loop until the end of the string.
		write(2, str++, 1); // Write each character to stderr.
}

// Function to handle the built-in 'cd' command.
int cd(char **argv, int i)
{
    // Check if the number of arguments for 'cd' is exactly 2 (cd + path).
	if (i != 2)
		return err("error: cd: bad arguments\n"), 1; // Print error and return 1 for failure.

    // Attempt to change the current directory to the one specified.
	if (chdir(argv[1]) == -1)
		// If changing directory fails, print an error message.
		return err("error: cd: cannot change directory to "), err(argv[1]), err("\n"), 1;

    return 0; // Return 0 for successful execution of 'cd'.
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

/bin/ls microshell.c
microshell.c

/bin/ls salut

;

; ;

; ; /bin/echo OK
OK

; ; /bin/echo OK ;
OK

; ; /bin/echo OK ; ;
OK

; ; /bin/echo OK ; ; ; /bin/echo OK
OK
OK

/bin/ls | /usr/bin/grep microshell
microshell
microshell.c

/bin/ls | /usr/bin/grep microshell | /usr/bin/grep micro
microshell
microshell.c

/bin/ls | /usr/bin/grep microshell | /usr/bin/grep micro | /usr/bin/grep shell | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro
microshell
microshell.c

/bin/ls | /usr/bin/grep microshell | /usr/bin/grep micro | /usr/bin/grep shell | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell
microshell
microshell.c

/bin/ls ewqew | /usr/bin/grep micro | /bin/cat -n ; /bin/echo dernier ; /bin/echo
dernier


/bin/ls | /usr/bin/grep micro | /bin/cat -n ; /bin/echo dernier ; /bin/echo ftest ;
     1	microshell
     2	microshell.c
dernier
ftest

/bin/echo ftest ; /bin/echo ftewerwerwerst ; /bin/echo werwerwer ; /bin/echo qweqweqweqew ; /bin/echo qwewqeqrtregrfyukui ;
ftest
ftewerwerwerst
werwerwer
qweqweqweqew
qwewqeqrtregrfyukui

/bin/ls ftest ; /bin/ls ; /bin/ls werwer ; /bin/ls microshell.c ; /bin/ls subject.fr.txt ;
a.out
leaks.res
microshell
microshell.c
out.res
test.sh
microshell.c

/bin/ls | /usr/bin/grep micro ; /bin/ls | /usr/bin/grep micro ; /bin/ls | /usr/bin/grep micro ; /bin/ls | /usr/bin/grep micro ;
microshell
microshell.c
microshell
microshell.c
microshell
microshell.c
microshell
microshell.c

/bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep b ; /bin/cat subject.fr.txt ;

/bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep w ; /bin/cat subject.fr.txt ;

/bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep w ; /bin/cat subject.fr.txt

/bin/cat subject.fr.txt ; /bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep b | /usr/bin/grep z ; /bin/cat subject.fr.txt

; /bin/cat subject.fr.txt ; /bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep b | /usr/bin/grep z ; /bin/cat subject.fr.txt

blah | /bin/echo OK
OK

blah | /bin/echo OK ;
OK

