/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:22:04 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/13 16:51:57 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_exec(char *param, char **envp)
{
	char	**params;
	char	*path;

	params = ft_split(param, ' ');
	path = path_handler(params[0], envp);
	if (execve(path, params, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(params[0], 2);
		ft_free_tab(params);
		exit(1);
	}
}

void	father(char **argv, char **envp, int *fd)
{
	int		out_fd;

	out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (out_fd < 0)
		msg_error("Error 4");
	dup2(fd[0], 0);
	dup2(out_fd, 1);
	close(fd[1]);
	close(fd[0]);
	ft_exec(argv[3], envp);
}

void	child(char **argv, char **envp, int *fd)
{
	int		in_fd;

	in_fd = open(argv[1], O_RDONLY);
	if (in_fd < 0)
		msg_error("Error 3");
	dup2(in_fd, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	ft_exec(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	printf("argc: %d\n", argc);
	while (*argv)
		printf("argv: %s\n", *argv++);
	if (argc != 5)
		msg_error("Error 1");
	if (pipe(fd) < 0)
		msg_error("Error 2");
	pid = fork();
	if (pid == 0) //hijo leera del in_file y escribira en el pipe
		child(argv, envp, fd);
	else //soy el padre
		father(argv, envp, fd);
	return (0);
}
