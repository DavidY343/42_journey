/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:17:28 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/16 18:07:24 by dyanez-m         ###   ########.fr       */
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

void	ft_result(char *result, int i)
{
	while (i > 0)
	{
		i--;
		write(1, &result[i], 1);
	}
}

int	ft_negative(int nbr)
{
	write(1, "-", 1);
	nbr *= -1;
	return (nbr);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	buffer[64];
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(base);
	if (!(is_valid_base(base)))
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base(nbr / len, base);
		ft_putnbr_base(-(nbr % len), base);
		return ;
	}
	else if (nbr < 0)
		nbr = ft_negative(nbr);
	if (nbr == 0)
		write(1, &base[i], 1);
	while (nbr > 0)
	{
		buffer[i] = base[nbr % len];
		nbr /= len;
		i++;
	}
	ft_result(buffer, i);
}
