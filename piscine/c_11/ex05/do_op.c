/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:48:27 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/31 12:23:20 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_all.h"

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr(147483648);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		ft_putnbr(nb);
	}
	else
	{
		digit = '0' + nb;
		write(1, &digit, 1);
	}
}

int	ft_atoi(char *str)
{
	int	pos;
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	pos = 0;
	while ((str[pos] >= 9 && str[pos] <= 13) || (str[pos] == 32))
		pos++;
	while (str[pos] == 43 || str[pos] == 45)
	{
		if (str[pos] == 45)
			sign *= -1;
		pos++;
	}
	while (str[pos] != '\0' && str[pos] >= 48 && str[pos] <= 57)
	{
		number *= 10;
		number += str[pos] - 48;
		pos++;
	}
	return (number * sign);
}

int	resolve(int n1, char op, int n2)
{
	int	sol;
	int	(*operate[5])(int, int);

	operate[0] = &ft_add;
	operate[1] = &ft_sub;
	operate[2] = &ft_mul;
	operate[3] = &ft_div;
	operate[4] = &ft_mod;
	sol = 0;
	if (op == '+')
		sol = operate[0](n1, n2);
	else if (op == '-')
		sol = operate[1](n1, n2);
	else if (op == '*')
		sol = operate[2](n1, n2);
	else if (op == '/')
		sol = operate[3](n1, n2);
	else if (op == '%')
		sol = operate[4](n1, n2);
	return (sol);
}

void	do_op(char *num1, char *operator, char *num2)
{
	int		n1;
	int		n2;
	char	op;
	int		sol;

	op = operator[0];
	n1 = ft_atoi(num1);
	n2 = ft_atoi(num2);
	if (op != '-' && op != '+' && op != '/' && op != '*' && op != '%')
		write(1, "0", 1);
	else if (n2 == 0 && op == '/')
		write(1, "Stop : division by zero", 23);
	else if (n2 == 0 && op == '%')
		write(1, "Stop : modulo by zero", 21);
	else
	{
		sol = resolve(n1, op, n2);
		ft_putnbr(sol);
	}
	write(1, "\n", 1);
}	

int	main(int argc, char **argv)
{
	if (argc == 4)
		do_op(argv[1], argv[2], argv[3]);
	return (0);
}
