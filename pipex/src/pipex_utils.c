/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:02:56 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/31 18:06:51 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	msg_error(char *text)
{
	ft_putstr_fd(text, 2);
	exit(1);
}

void	ft_free(char **string)
{
	int	i;

	i = -1;
	while (string[++i])
		free(string[i]);
	free(string);
}

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	return (envp[i] + 5);
}

char	*path_handler(char *param, char **envp)
{
	int		i;
	char	*exec;
	char	**paths;

	i = -1;
	paths = ft_split(get_path(envp), ':');
	while (paths[++i])
	{
		exec = ft_strjoin(ft_strjoin(paths[i], "/"), param);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free(param);
			return (exec);
		}
		free(exec);
	}
	ft_free(paths);
	return (param);
}
/*
char	*path_handler(char *param, char **envp)
{
	int		i;
	char	*exec;
	char	**paths;
	char	**params;

	i = -1;
	paths = ft_split(get_path(envp), ':');
	params = ft_split(param, ' ');
	while (paths[++i])
	{
		exec = ft_strjoin(ft_strjoin(paths[i], "/"), params[0]);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free(params);
			return (exec);
		}
		free(exec);
	}
	ft_free(paths);
	ft_free(params);
	return (param);
}*/
