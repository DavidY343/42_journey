/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:09:48 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/24 17:44:29 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	is_valid_base(char *base);
int	ft_strlen(char *str);

void	ft_result(char *str)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

char	*ft_malloc(int nbr, int *p, char *base)
{
	int		i;
	int		nb;
	int		len;
	char	*buffer;

	i = 0;
	len = ft_strlen(base);
	if (!(is_valid_base(base)))
		return (0);
	if (nbr > 0)
		nb = nbr;
	else
		nb = -nbr;
	if (nbr < 0)
		i++;
	while (nb > 0)
	{
		nb /= len;
		i++;
	}
	buffer = (char *)malloc(sizeof(char) * (i + 1));
	buffer[i] = '\0';
	*p = i;
	return (buffer);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	char	*buffer;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(base);
	buffer = ft_malloc(nbr, &i, base);
	if (!buffer)
		return (0);
	if (nbr < 0)
	{
		nbr = -nbr;
		buffer[i - 1] = '-';
	}
	i = 0;
	if (nbr == 0)
		buffer[i] = base[i];
	while (nbr > 0)
	{
		buffer[i] = base[nbr % len];
		nbr /= len;
		i++;
	}
	ft_result(buffer);
	return (buffer);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	char	*sol;

	if (!(is_valid_base(base_from)) || !(is_valid_base(base_to)))
		return (0);
	number = 0;
	number = ft_atoi_base(nbr, base_from);
	sol = ft_putnbr_base(number, base_to);
	return (sol);
}
