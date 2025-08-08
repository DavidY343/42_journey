/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:14:34 by jonjimen          #+#    #+#             */
/*   Updated: 2025/01/17 17:06:25 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static int	get_index(char *line, int i)
{
	while (check_space(line[i]))
		i++;
	return (i);
}

static t_texture	*new_texture(char *line)
{
	t_texture	*list;

	list = (t_texture *)ft_calloc(sizeof(t_texture), 1);
	if (!list)
		return (NULL);
	while (check_space(*line))
		line++;
	if ((!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)))
	{
		list->name = ft_substr(line, 0, 2);
		list->value = ft_substr(line, get_index(line, 2), ft_strlen(line));
	}
	else if ((!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1)))
	{
		list->name = ft_substr(line, 0, 1);
		list->value = ft_substr(line, get_index(line, 1), ft_strlen(line));
	}
	list->next = NULL;
	return (list);
}

static void	next_texture(t_texture **current, t_texture *added)
{
	t_texture	*temp;

	if (!*current)
	{
		(*current) = added;
		return ;
	}
	temp = *current;
	while (temp->next)
		temp = temp->next;
	temp->next = added;
}

int	fill_texture_s(t_parse **map)
{
	int			i;
	t_texture	*temp;

	i = 0;
	while ((*map)->texture_2d[i])
	{
		temp = new_texture((*map)->texture_2d[i++]);
		if (!temp)
			return (0);
		next_texture(&(*map)->texture_s, temp);
	}
	return (1);
}
