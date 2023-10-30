/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:22:04 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/25 16:48:57 by root             ###   ########.fr       */
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

void	base_case(t_params *params)
{
	params->in_fd = open(params->argv[1], O_RDONLY);
	if (params->in_fd < 0)
		msg_error("Error al abrir el fichero de entrada");
	params->out_fd = open(params->argv[params->argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (params->out_fd < 0)
		msg_error("Error al abrir el fichero de salida");
	params->i = 2;
}

void	param_setter(t_params *params, char **argv, char **envp)
{
	params->argv = argv;
	params->envp = envp;
}

/*Pid == 0 -> hijo y pid != 0 -> padre*/
int	main(int argc, char **argv, char **envp)
{
	t_params	params;

	if (argc < 5)
		msg_error("Error en el número de argumentos");
	params.argc = argc;
	param_setter(&params, argv, envp);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		here_doc_case(&params);
	else
		base_case(&params);
	pipex(&params);
	return (0);
}
