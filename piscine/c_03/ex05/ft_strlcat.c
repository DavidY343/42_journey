/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:25:11 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/15 17:41:47 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	pos1;
	unsigned int	pos2;
	unsigned int	len_src;

	pos2 = 0;
	pos1 = 0;
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	while (dest[pos1] != '\0')
		pos1++;
	if (size == 0 || size <= pos1)
		return (len_src + size);
	while (src[pos2] != '\0' && size > (pos1 + 1))
	{
		dest[pos1] = src[pos2];
		pos2++;
		pos1++;
	}
	dest[pos1] = '\0';
	return ((pos1 - pos2) + len_src);
}
