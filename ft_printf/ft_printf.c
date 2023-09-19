/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:23:33 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/09/19 12:45:28 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(const char str, va_list args)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (str == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (str == 'p')
		len += ft_print_ptr(va_arg(args, void *));
	else if (str == 'd' || str == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (str == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (str == 'x' || str == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), str);
	else if (str == '%')
		len += ft_printpercent();
	return (len);
}

int	ft_printf(const char *string, ...)
{
	int	i;
	va_list	args;
	int	counter;

	i = 0;
	counter = 0;
	if (!string)
		return (0);
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			counter += ft_type((string + i), args);
		}
		else
		{
			ft_putchar_fd((string + i), 1);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}
