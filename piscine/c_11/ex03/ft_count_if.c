/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:39:19 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/29 19:41:40 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f) (char*))
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			counter++;
		i++;
	}
	return (counter);
}
