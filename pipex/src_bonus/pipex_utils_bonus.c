/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:02:56 by dyanez-m          #+#    #+#             */
/*   Updated: 2024/07/31 17:05:25 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	msg_error(char *text)
{
	perror(text);
	exit(0);
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
