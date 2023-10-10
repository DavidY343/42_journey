# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "ft_printf/libft/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	int		pos;

	pos = ft_strlen(s);
	result = (char *)malloc((pos + 1) * sizeof(char));
	if (!result)
		return (0);
	pos = 0;
	while (s[pos] != '\0')
	{
		result[pos] = s[pos];
		pos++;
	}
	result[pos] = '\0';
	return (result);
}

static int	ft_stringcount(char *str, char sep)
{
	int	i;
	int	counter;
	int	new_string;

	new_string = 1;
	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == sep)
			new_string = 1;
		else
		{
			if (new_string == 1)
			{
				counter++;
				new_string = 0;
			}
		}
		i++;
	}
	return (counter);
}

static char	*put_string(char *str, char charset)
{
	int		len;
	char	*string;
	int		i;

	len = 0;
	i = 0;
	while (str[len] != '\0' && *(str + len) != charset)
		len++;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (0);
	while (i < len)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

static char	*process_string(char **sol, char *str, char charset, int i)
{
	sol[i] = put_string(str, charset);
	if (!sol[i])
	{
		while (i >= 0)
		{
			free(sol[i]);
			i--;
		}
		free(sol);
		return (0);
	}
	return (str);
}

static char	**ft_split_aux(char **sol, char *str, char charset)
{
	int	i;
	int	new_string;

	new_string = 1;
	i = 0;
	while (*str != '\0')
	{
		if (*str == charset)
			new_string = 1;
		else
		{
			if (new_string == 1)
			{
				str = process_string(sol, str, charset, i);
				if (!str)
					return (0);
				i++;
				new_string = 0;
			}
		}
		str++;
	}
	sol[i] = 0;
	return (sol);
}

char	**ft_split(char const *s, char c)
{
	char	**sol;
	char	*copy;

	copy = ft_strdup(s);
	if (!copy)
		return (0);
	sol = malloc(sizeof(char *) * (ft_stringcount(copy, c) + 1));
	if (!sol)
	{
		free(copy);
		return (0);
	}
	sol = ft_split_aux(sol, copy, c);
	free(copy);
	return (sol);
}

void    exec_cmd(int in, int out, char *cmd)
{
    char    **args;
    pid_t   pid;

    args = ft_split(cmd, ' ');
    pid = fork();
    if (pid == 0)
    {
        dup2(in, 0);
        dup2(out, 1);
        execve(args[0], args, NULL);
        perror("execve");
        exit(1);
    }
    else if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
}

int main(int argc, char **argv)
{
    int     fd[2];
    int     file_in;
    int     file_out;

    if (argc != 5)
        return (1);
    if (pipe(fd) == -1)
        return (1);
    file_in = open(argv[1], O_RDONLY);
    file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_in < 0 || file_out < 0)
        return (1);
    
    exec_cmd(file_in, fd[1], argv[2]);
    close(fd[1]);
    
    exec_cmd(fd[0], file_out, argv[3]);
    close(fd[0]);
    
    wait(NULL);
    wait(NULL);

    close(file_in);
    close(file_out);

    return (0);
}
