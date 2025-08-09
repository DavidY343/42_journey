/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:36:57 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/23 13:19:42 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*result;
	int		pos;

	pos = 0;
	while (src[pos] != '\0')
		pos++;
	result = (char *)malloc((pos + 1) * sizeof(char));
	pos = 0;
	if (src[pos] == '\0')
		return (result);
	while (src[pos] != '\0')
	{
		result[pos] = src[pos];
		pos++;
	}
	result[pos] = '\0';
	return (result);
}
