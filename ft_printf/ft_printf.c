/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:23:33 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/09/18 13:05:18 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char c, const char *str)
{

}
int	ft_printf(const char *string, ...)
{
	int	i;
	va_list	args;
	int	counter;

	i = 0;
	counter = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			//ft_type(string[i], string);
			i++;
		}
		else
		{
			ft_putchar_fd(string[i], 1);
			counter++;
		}
		i++;
	}
	return (counter);
}
