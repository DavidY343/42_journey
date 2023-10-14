/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:02:56 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/14 16:18:20 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	msg_error(char *text)
{
	perror(text);
	exit(1);
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
	char	*path_part;
	char	**params;

	i = -1;
	paths = ft_split(get_path(envp), ':');
	params = ft_split(param, ' ');
	while (paths[++i])
	{
		path_part = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(path_part, params[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(params);
			return (exec);
		}
		free(exec);
	}
	ft_free_tab(paths);
	ft_free_tab(params);
	return (param);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}