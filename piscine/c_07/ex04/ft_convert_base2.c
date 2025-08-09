/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:31:55 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/24 17:11:19 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (base[i] == '+' || base[i] == '-' || base[i] == 32
			|| (base[i] >= 9 && base[i] <= 13))
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

int	validate_is_space(char *str, char *base, int len)
{
	int		pos;
	int		sign;
	int		number;
	char	digit;

	number = 0;
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
	while (str[pos] != '\0' && base_number(str[pos], base) != -1)
	{
		digit = base_number(str[pos], base);
		number = (number * len) + digit;
		pos++;
	}
	return (sign * number);
}

int	ft_atoi_base(char *str, char *base)
{
	int	number;
	int	len;

	number = 0;
	len = ft_strlen(base);
	if (!(is_valid_base(base)))
		return (0);
	number = validate_is_space(str, base, len);
	return (number);
}
