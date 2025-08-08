/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:22:39 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/10 19:46:55 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void)
{	
	int		i;
	char	number;

	i = 0;
	number = '0';
	while (i < 10)
	{
		write(1, &number, 1);
		i++;
		number++;
	}
}
