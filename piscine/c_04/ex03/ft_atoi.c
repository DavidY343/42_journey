/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:31:04 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/16 11:09:32 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
