/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:44:42 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/15 17:06:21 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	pos1;
	unsigned int	pos2;

	pos2 = 0;
	pos1 = 0;
	while (dest[pos1] != '\0')
	{
		pos1++;
	}
	while (src[pos2] != '\0' && nb > 0)
	{
		dest[pos1] = src[pos2];
		pos2++;
		pos1++;
		nb--;
	}
	dest[pos1] = '\0';
	return (dest);
}
