/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:41:38 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/30 18:10:49 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	pos1;
	unsigned int	pos2;

	pos2 = 0;
	pos1 = 0;
	while (dest[pos1] != '\0')
	{
		pos1++;
	}
	while (src[pos2] != '\0' && nb > 0)
	{
		dest[pos1] = src[pos2];
		pos2++;
		pos1++;
		nb--;
	}
	dest[pos1] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	pos;

	pos = 0;
	while (src[pos] != '\0' && pos < n)
	{
		dest[pos] = src[pos];
		pos++;
	}
	if (n == pos)
		dest[pos] = '\0';
	while (pos < n)
	{
		dest[pos] = '\0';
		pos ++;
	}
	return (dest);
}

int	ft_atoi_aux(char *str, int len)
{
	int	result;
	int	pos;

	result = 0;
	pos = 0;
	if (len > 13)
		return (0);
	while (str[pos] >= '0' && str[pos] <= '9' && len > 3)
	{
		result = (result * 10) + (str[pos] - 48);
		pos++;
		len--;
	}
	return (result);
}

void	control_error(char *buffer, char *f_line)
{
	ft_putstr("map error\n");
	free(buffer);
	free(f_line);
	exit(1);
}

char	*read_stdin(void)
{
	char	*f_line;
	char	*buffer;
	int		n_lines;
	ssize_t	bytes;

	buffer = (char *)malloc(sizeof(char) * 1024);
	f_line = (char *)malloc(sizeof(char) * 1024);
	bytes = read(0, f_line, 1024);
	n_lines = ft_atoi_aux(f_line, bytes - 1);
	if (n_lines < 1)
		control_error(buffer, f_line);
	ft_strncpy(buffer, f_line, bytes);
	while (n_lines > 0)
	{
		bytes = read(0, f_line, 1024);
		if (n_lines == 1)
			ft_strncat(buffer, f_line, bytes - 1);
		else
			ft_strncat(buffer, f_line, bytes);
		n_lines--;
	}
	free(f_line);
	return (buffer);
}
