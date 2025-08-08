/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalah-d <lsalah-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:34:41 by lsalah-d          #+#    #+#             */
/*   Updated: 2023/08/27 19:15:21 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int		pos;

	pos = 0;
	result = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (src[pos] == '\0')
		return (result);
	while (src[pos] != '\0')
	{
		result[pos] = src[pos];
		pos++;
	}
	result[pos] = '\0';
	return (result);
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	number;

	number = 0;
	if (*str < '0' || *str > '9')
		return (-1);
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	return (number);
}

void	ft_putstr(char *str, int op)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	if (op >= 1)
		write(1, " ", 1);
}
