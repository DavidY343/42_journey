/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:28:50 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/21 17:24:23 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	low;
	int	high;
	int	half;

	low = 0;
	high = nb;
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	while (low <= high)
	{
		half = (low + high) / 2;
		if (half == 0)
			return (0);
		if ((nb / half) == half && (nb % half == 0))
			return (half);
		else if ((nb / half) < half)
			high = half - 1;
		else
			low = half + 1;
	}
	return (0);
}
