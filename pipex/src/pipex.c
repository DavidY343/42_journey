/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:22:04 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/04 16:41:28 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		in_fd;
	int		out_fd;
	pid_t	pid;
	int		i;

	i = 2;
	if (argc != 5)
	{
		printf("Error\n");
		exit(0);
	}
	in_fd = open(argv[1], O_RDONLY);
	if (in_fd < 0)
	{
		printf("Error entrada\n");
		exit(0);
	}
	out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (out_fd < 0)
	{
		printf("Error salida\n");
		exit(0);
	}
	if (pipe(fd) < 0)
	{
		printf("Error crear pipe\n");
		exit(0);
	}
	while (i > argc - 1)
	{
		pid = fork();
		if (pid == 0) //hijo leera del in_file y escribira en el pipe
		{
			close(1);
			dup(fd[1]);
			close(0);
			dup(fd[0]);
			close(fd[1]);
			close(fd[0]);
			char *args[] = {argv[i], "-1"};
			execve(argv[i], args, envp);

		}
		else //soy el padre
		{
			wait(NULL);
			close(in_fd);
			close(fd[1]);
			in_fd = fd[0];
			if (i == argc - 2) {
				dup2(out_fd, 1);
				close(out_fd);
			}
		}
		i++;
	}
	return (0);
}
