/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:52:17 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/10 19:42:38 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb2(void)
{
	int		par1;
	int		par2;
	char	buffer[7];

	par1 = 0;
	while (par1 < 100)
	{
		par2 = par1 + 1;
		while (par2 < 100)
		{
			buffer[0] = '0' + par1 / 10;
			buffer[1] = '0' + par1 % 10;
			buffer[2] = ' ';
			buffer[3] = '0' + par2 / 10;
			buffer[4] = '0' + par2 % 10;
			buffer[5] = ',';
			buffer[6] = ' ';
			if (par1 == 98 && par2 == 99)
				write(1, buffer, 5);
			else
				write(1, buffer, 7);
			par2++;
		}
		par1++;
	}
}
