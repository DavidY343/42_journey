/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:31:38 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/30 12:04:50 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	pos;
	unsigned int	len;

	pos = 0;
	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	if (size != 0)
	{
		while (src[pos] != '\0' && pos < size - 1)
		{
			dest[pos] = src[pos];
			pos++;
		}
		dest[pos] = '\0';
	}
	return (len);
}
