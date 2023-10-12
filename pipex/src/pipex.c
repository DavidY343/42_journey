/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:22:04 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/12 16:13:36 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	father(char **argv, char **envp, int *fd)
{
	int		out_fd;

	out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (out_fd < 0)
		msg_error("Error");
	dup2(fd[0], 0);
	dup2(out_fd, 1);
	close(fd[1]);
	close(fd[0]);
	ft_exec();
}

void	child(char **argv, char **envp, int *fd)
{
	int		in_fd;

	in_fd = open(argv[1], O_RDONLY);
	if (in_fd < 0)
		msg_error("Error");
	dup2(in_fd, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	ft_exec();
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		msg_error("Error");
	if (pipe(fd) < 0)
		msg_error("Error");
	pid = fork();
	if (pid == 0) //hijo leera del in_file y escribira en el pipe
		child(argv, envp, fd);
	else //soy el padre
		father(argv, envp, fd);
	return (0);
}
