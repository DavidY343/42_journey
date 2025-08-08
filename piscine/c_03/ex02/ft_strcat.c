/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:07:29 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/15 13:03:08 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*original;
	int		pos1;
	int		pos2;

	original = dest;
	pos2 = 0;
	pos1 = 0;
	while (dest[pos1] != '\0')
	{
		pos1++;
	}
	while (src[pos2] != '\0')
	{
		dest[pos1] = src[pos2];
		pos2++;
		pos1++;
	}
	dest[pos1] = '\0';
	return (original);
}
