/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:02:56 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/16 11:52:31 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	pipex_child(t_params *params)
{
	if (params->i == 2)
	{
		dup2(params->in_fd, 0);
		close(params->in_fd);
	}
	if (params->i != (params->argc - 2))
	{
		dup2(params->fd[1], 1);
		close(params->fd[0]);
	}
	if (params->i == (params->argc - 2))
	{
		dup2(params->out_fd, 1);
		close(params->out_fd);
	}
	ft_exec(params->argv[params->i], params->envp);
}

void	pipex_dad(t_params *params)
{
	if (params->i != (params->argc - 2))
	{
		close(params->fd[1]);
		dup2(params->fd[0], 0);
	}
	else
		close(params->fd[0]);
}

void	pipex(t_params *params)
{
	while (params->i < params->argc - 1)
	{
		if (params->i != (params->argc - 2))
		{
			if (pipe(params->fd) < 0)
				msg_error("Error en la creación del pipe");
		}
		params->pid = fork();
		if (params->pid < 0)
			msg_error("Error en la creación del fork");
		else if (params->pid == 0)
			pipex_child(params);
		else
			pipex_dad(params);
		params->i++;
	}
	while (params->pid != wait(NULL))
		;
}
