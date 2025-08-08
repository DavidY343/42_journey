/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:42:06 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/31 14:20:46 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (i < length - 1 && flag)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			flag = 0;
		i++;
	}
	i = 0;
	while (i < length - 1 && flag == 0)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}
