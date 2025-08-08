/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:35:35 by jonjimen          #+#    #+#             */
/*   Updated: 2023/08/30 16:24:12 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		ft_atoi(char **str);
int		ft_strlen(char *str);
void	rel_hd(int num, char **hd);

char	*get_header(char *buffer)
{
	int		len;
	char	*header;

	len = 0;
	while (buffer[len] != '\n' && buffer[len])
		len++;
	header = (char *)malloc(sizeof(char) * len + 1);
	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0')
	{
		header[len] = buffer[len];
		len++;
	}
	header[len] = '\0';
	return (header);
}

int	check_header(char **hd)
{
	int	num;
	int	len;

	if (hd == 0)
		return (0);
	num = ft_atoi(hd);
	if (num == -1)
		return (0);
	if (num == 0)
	{
		rel_hd(1, hd);
		return (0);
	}
	len = ft_strlen(*hd);
	if (len != 3)
	{
		rel_hd(num, hd);
		return (0);
	}
	if ((*hd)[0] == (*hd)[1] || (*hd)[0] == (*hd)[2] || (*hd)[1] == (*hd)[2])
	{
		rel_hd(num, hd);
		return (0);
	}
	return (num);
}

char	*next_line(char *buffer)
{
	while (*buffer != '\n')
		buffer++;
	buffer++;
	return (buffer);
}

int	len_line(int *j, char *buf, char *hd)
{
	int	len;

	len = 0;
	while (buf[*j] != '\n' && buf[*j] != '\0')
	{
		if ((buf[*j] != hd[0] && buf[*j] != hd[1] && buf[*j] != hd[2]))
			return (0);
		(*j)++;
		len++;
	}
	return (len);
}

int	check_matrix(char *buf, char *hd, int n)
{
	int	i;
	int	j;
	int	len;
	int	len_a;

	i = 1;
	j = 0;
	len = 0;
	buf = next_line(buf);
	while (i <= n)
	{
		len = len_line(&j, buf, hd);
		if (buf[j] == '\n')
			j++;
		if (i == 1)
			len_a = len;
		if (len != len_a || len < 1)
			return (0);
		if ((buf[j] == '\0' && i != n) || (buf[j] != '\0' && i == n))
			return (0);
		i++;
	}
	return (len * n);
}
