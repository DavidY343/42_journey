/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:19:14 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/11 15:08:36 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	contador;

	contador = 0;
	while (str[contador] != '\0' )
	{
		contador++;
	}
	return (contador);
}
