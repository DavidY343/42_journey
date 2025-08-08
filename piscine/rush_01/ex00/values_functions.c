/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalah-d <lsalah-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:09:48 by lsalah-d          #+#    #+#             */
/*   Updated: 2023/08/27 19:42:16 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ft.h"

void	insert(int key, char *value, t_node **list);

int	ft_strlen_value(char *value)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (*(value + i) == ' ')
		i++;
	while (*(value + i) != '\0')
	{
		if (*(value + i) == ' ' && *(value + i + 1) != ' ')
			j++;
		if (*(value + i) != ' ')
			j++;
		i++;
	}
	return (j);
}

char	*ft_correct_value(char *value)
{
	int		i;
	char	*result;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen_value(value);
	result = (char *)malloc((len + 1) * sizeof(char));
	while (*(value + i) == ' ')
		i++;
	while (*(value + i) != '\0')
	{
		if (*(value + i) == ' ' && *(value + i + 1) != ' ')
			result[j++] = *(value + i);
		if (*(value + i) != ' ')
			result[j++] = *(value + i);
		i++;
	}
	result[j] = '\0';
	return (result);
}

void	reset_values(int *i, int *j, int op)
{
	if (op == 0)
	{
		*i = 0;
		*j = 0;
	}
	else
	{
		*i = 0;
		*j = 1;
	}
}

void	read_dict_aux(t_node **list, int fd)
{
	char	key[512];
	char	value[512];
	int		i;
	int		j;
	char	c;

	reset_values(&i, &j, 0);
	while (read(fd, &c, 1) > 0)
	{
		if (c == ':')
		{
			key[i] = '\0';
			reset_values(&i, &j, 1);
		}
		else if (c == '\n')
		{
			value[i] = '\0';
			insert(atoi(key), ft_strdup(ft_correct_value(value)), list);
			reset_values(&i, &j, 0);
		}
		else if (j == 0)
			key[i++] = c;
		else
			value[i++] = c;
	}
}

int	read_dict(char *file, t_node **list)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	read_dict_aux(list, fd);
	close(fd);
	return (0);
}
