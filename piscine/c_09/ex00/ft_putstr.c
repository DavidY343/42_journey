/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:00:44 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/28 13:00:53 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	contador;

	contador = 0;
	while (str[contador] != '\0' )
	{
		write(1, &str[contador], 1);
		contador++;
	}
}
