/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:22:04 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/04 14:17:52 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv)
{
	int		f10;
	int		fd[2];
	int		in_fd;
	int		out_fd;
	pid_t	pid;

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
	out_fd = open(argv[1], O_RDONLY);
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
	pid = fork();
	if (pid == 0) //hijo
	{
		close(1);
		dup(fd[1]);
		close(fd[1]);
		close(fd[0]);
	}
	else //soy el padre
	{

	}
}
