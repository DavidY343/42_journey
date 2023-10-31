/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:13:55 by david             #+#    #+#             */
/*   Updated: 2023/10/31 17:14:22 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	here_doc_terminal(t_params *params)
{
	char	*line;

	close(params->fd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, params->argv[2], ft_strlen(params->argv[2])) == 0)
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, params->fd[1]);
		free(line);
	}
}

void	here_doc(t_params *params)
{
	if (pipe(params->fd) == -1)
		exit(0);
	params->pid = fork();
	if (params->pid == -1)
		exit(0);	
	if (!params->pid)
	{
		here_doc_terminal(params);
	}
	else
	{
		close(params->fd[1]);
		dup2(params->fd[0], 0);
		wait(NULL);
	}
}

void	here_doc_case(t_params *params)
{
	if (params->argc < 6)
		msg_error("Error en el número de argumentos");
	params->i = 3;
	params->out_fd = open(params->argv[params->argc - 1],
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (params->out_fd < 0)
		msg_error("Error al abrir el fichero de salida");
	here_doc(params);
}
