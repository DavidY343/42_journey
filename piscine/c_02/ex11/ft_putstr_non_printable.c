/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:57:02 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/14 17:30:58 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		pos;
	char	buffer[3];

	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] >= 32 && str[pos] <= 126)
			write(1, &str[pos], 1);
		else
		{
			buffer[0] = '\\';
			buffer[1] = "0123456789abcdef"[(unsigned char)str[pos] / 16];
			buffer[2] = "0123456789abcdef"[(unsigned char)str[pos] % 16];
			write(1, buffer, sizeof(buffer));
		}
		pos++;
	}
}
