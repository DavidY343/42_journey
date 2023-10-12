/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:08:04 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/09/16 14:04:24 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		pos;

	pos = ft_strlen(s);
	result = (char *)malloc((pos + 1) * sizeof(char));
	if (!result)
		return (0);
	pos = 0;
	while (s[pos] != '\0')
	{
		result[pos] = s[pos];
		pos++;
	}
	result[pos] = '\0';
	return (result);
}
