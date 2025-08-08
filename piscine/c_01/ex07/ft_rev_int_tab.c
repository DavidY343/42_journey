/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:07:59 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/14 11:03:55 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	numero;

	i = 0;
	while (i < (size / 2))
	{
		numero = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i -1] = numero;
		i++;
	}
}
