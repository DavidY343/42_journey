/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:22:04 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/17 16:52:50 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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

/*Pid == 0 -> hijo y pid != 0 -> padre*/
int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		msg_error("Error en el número de argumentos");
	if (pipe(fd) < 0)
		msg_error("Error en la creación del pipe");
	pid = fork();
	if (pid < 0)
		msg_error("Error en la creación del fork");
	else if (pid == 0)
		child(argv, envp, fd);
	else
		father(argv, envp, fd);
	return (0);
}
