/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:02:00 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/09/19 12:45:44 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_c(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
	}
	return (i);	
}

static int	ft_p_len_in_base(unsigned long long p, char *base, int base_len)
{
	int		i;

	i = 0;
	while (p > 0)
    {
        p /= base_len;
        i++;
    }
	return (i);
}

static void	ft_write_ptr(unsigned long long p, int base_len)
{
	if (p >= base_len)
	{
		ft_put_ptr(p / base_len);
		ft_put_ptr(p % base_len);
	}
	else
	{
		if (p <= 9)
			ft_putchar_fd((p + '0'), 1);
		else
			ft_putchar_fd((p - 10 + 'a'), 1);
	}
}
int	ft_putptr_c(void *ptr)
{
	unsigned long long p;
	int	len;
	int base_len;

	p = (unsigned long long)ptr;
	base_len = ft_strlen(HEX_LOWCASE);
	len = ft_p_len_in_base(p, HEX_LOWCASE, base_len);
	ft_write_ptr(p, base_len);
	return (len);
}