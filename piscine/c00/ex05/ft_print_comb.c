/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:54:17 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/10 19:41:38 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void)
{
	char	buffer[5];

	buffer[3] = ',';
	buffer[4] = ' ';
	buffer[0] = '0';
	while (buffer[0] <= '7')
	{
		buffer[1] = buffer[0] + 1;
		while (buffer[1] <= '8')
		{
			buffer[2] = buffer[1] + 1;
			while (buffer[2] <= '9')
			{
				if (buffer[0] == '7' && buffer[1] == '8' && buffer[2] == '9' )
					write(1, buffer, 3);
				else
					write(1, buffer, sizeof(buffer));
				buffer[2]++;
			}
			buffer[1]++;
		}
		buffer[0]++;
	}		
}
