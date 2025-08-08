/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:51:40 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/16 16:48:07 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	is_valid_base(char *base)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(base);
	i = 0;
	if (len <= 1)
		return (0);
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	base_number(char number, char *base)
{
	int	pos;

	pos = 0;
	while (base[pos] != '\0')
	{
		if (number == base[pos])
			return (pos);
		pos++;
	}
	return (-1);
}

int	validate_is_space(char *str, int *p)
{
	int	pos;
	int	sign;

	sign = 1;
	pos = 0;
	while ((str[pos] >= 9 && str[pos] <= 13) || (str[pos] == 32))
		pos++;
	while (str[pos] == 43 || str[pos] == 45)
	{
		if (str[pos] == 45)
			sign *= -1;
		pos++;
	}
	*p = pos;
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	pos;
	int	sign;
	int	number;
	int	len;
	int	digit;

	sign = 1;
	number = 0;
	pos = 0;
	len = ft_strlen(base);
	if (!(is_valid_base(base)))
		return (0);
	sign = validate_is_space(str, &pos);
	while (str[pos] != '\0')
	{
		digit = base_number(str[pos], base);
		number = (number * len) + digit;
		pos++;
	}
	return (number * sign);
}
