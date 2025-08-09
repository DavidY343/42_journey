/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:47:59 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/21 15:57:10 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	num;

	num = 5;
	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (nb / num >= num)
	{
		if (nb % num == 0 || nb % (num + 2) == 0)
			return (0);
		num = num + 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	if (i <= 2)
		return (2);
	if (i % 2 == 0)
		i++;
	while (1)
	{
		if (ft_is_prime(i))
			return (i);
		i = i + 2;
	}
}
