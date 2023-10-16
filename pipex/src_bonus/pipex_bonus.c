/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:22:04 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/16 12:15:32 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_exec(char *param, char **envp)
{
	char	**params;
	char	*path;

	params = ft_split(param, ' ');
	path = path_handler(params[0], envp);
	execve(path, params, envp);
	perror("pipex: command not found: params");
	perror(params[0]);
	perror("\n");
	ft_free(params);
	exit(127);
}

void	father(char **argv, char **envp, int *fd)
{
	int		out_fd;

	out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd < 0)
		msg_error("Error al abrir el fichero de salida");
	dup2(fd[0], 0);
	dup2(out_fd, 1);
	close(fd[1]);
	close(fd[0]);
	close(out_fd);
	ft_exec(argv[3], envp);
}

void	child(char **argv, char **envp, int *fd)
{
	int		in_fd;

	in_fd = open(argv[1], O_RDONLY);
	if (in_fd < 0)
		msg_error("Error al abrir el fichero de entrada");
	dup2(in_fd, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	close(in_fd);
	ft_exec(argv[2], envp);
}

void	here_doc_case()
{}

void	base_case()
{
	while (i > argc - 1)
	{
		pid = fork();
		if (pid == 0) 
		{
			dup2(fd[1], 1);
			dup2(fd[0], 0);
			close(fd[1]);
			close(fd[0]);
			ft_exec(argv[i], envp);
		}
		else
		{
			wait(NULL);
			close(in_fd);
			close(fd[1]);
			in_fd = fd[0];
			if (i == argc - 2)
			{
				dup2(out_fd, 1);
				close(out_fd);
			}
		}
		i++;
	}
}
/*Pid == 0 -> hijo y pid != 0 -> padre*/
int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
		msg_error("Error en la creación del pipe");
	base_case();
	return (0);
}
