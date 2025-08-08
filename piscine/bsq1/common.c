/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:31:55 by jonjimen          #+#    #+#             */
/*   Updated: 2023/08/30 18:00:25 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
		pos++;
	return (pos);
}

void	rel_hd(int num, char **hd)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	*hd = *hd - len;
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(2, str, 1);
		str++;
	}
}

int	ft_atoi(char **str)
{
	int	len;
	int	result;

	result = 0;
	len = ft_strlen(*str);
	if (**str < '0' || **str > '9' || len > 13)
		return (-1);
	while (**str >= '0' && **str <= '9' && len > 3)
	{
		result = (result * 10) + **str - 48;
		(*str)++;
		len--;
	}
	return (result);
}

void	free_memory(char **matrix, char *buf, char *hd, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	free(buf);
	free(hd);
}
