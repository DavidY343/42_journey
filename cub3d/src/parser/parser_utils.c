/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:43:33 by jonjimen          #+#    #+#             */
/*   Updated: 2025/01/17 17:05:50 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	check_space(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	intlen(int number)
{
	int	length;

	length = 0;
	if (number < 0)
		number--;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

int	ft_len_arr(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

int	longest_line(char **map)
{
	int	i;
	int	max;

	i = -1;
	max = ft_strlen(map[0]);
	while (map[++i])
		if ((int)ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
	return (max);
}

size_t	ft_len(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
