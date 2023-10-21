/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:22:04 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/17 21:07:50 by dyanez-m         ###   ########.fr       */
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

void	here_doc_case()
{}
/*
void	base_case()
{

}*/

void	param_setter(t_params *params, char **argv, char **envp)
{
	params->argv = argv;
	params->envp = envp;
	params->in_fd = open(argv[1], O_RDONLY);
}

/*Pid == 0 -> hijo y pid != 0 -> padre*/
int	main(int argc, char **argv, char **envp)
{
	t_params	params;

	params.argc = argc;
	params.out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	param_setter(&params, argv, envp);
	if (params.in_fd < 0)
		msg_error("Error al abrir el fichero de entrada");
	if (params.out_fd < 0)
		msg_error("Error al abrir el fichero de salida");
	params.i = 2;
	if (argc < 5)
		msg_error("Error en el número de argumentos");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		here_doc_case();
	while (params.i < argc - 1)
	{
		// 1 .- Si no es el ultimo proceso -> Crear pipe
		if (params.i != (argc - 2))
		{
			if (pipe(params.fd) < 0)
				msg_error("Error en la creación del pipe");
		}
		// 2 .- Crear fork
		params.pid = fork();
		if (params.pid < 0)
			msg_error("Error en la creación del fork");
		// 3.- redirecciones + limpieza
		else if (params.pid == 0) // hijo 
		{
			if (params.i == 2) // entrada primer caso
			{
				dup2(params.in_fd, 0);
				close(params.in_fd);
			}
			if (params.i != 2) // entrada caso general
			{
				dup2(params.p0, 0);
				close(params.p0);
			}
			if (params.i != (argc - 2)) // salida caso general
			{
				dup2(params.fd[1], 1);
				close(params.fd[1]);
				close(params.fd[0]);
			}
			if (params.i == (argc - 2)) // salida ultimo caso
			{
				dup2(params.out_fd, 1);
				close(params.out_fd);
			}
			ft_exec(argv[params.i], envp);
		}
		else // padre 
		{
			if (params.i != (argc - 2)) // entrada caso general
			{
				close(params.fd[1]);
				params.p0 = params.fd[0];
			}
			else // entrada ultimo caso
			{
				close(params.fd[0]);
			}
		}
		params.i = params.i + 1;
	}
	while (params.pid != wait(NULL))
		;
	return (0);
}
