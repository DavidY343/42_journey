/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:44:07 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/24 16:26:23 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	pos;

	pos = 0;
	while (src[pos] != '\0')
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = '\0';
	return (dest);
}

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

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total_len;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i < size - 1)
			total_len += ft_strlen(sep);
		i++;
	}
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_len;
	int		i;

	if (size <= 0)
	{
		result = (char *)malloc(sizeof(char));
		result[0] = '\0';
		return (result);
	}
	total_len = ft_total_len(size, strs, sep);
	result = (char *)malloc((total_len + 1) * sizeof(char));
	ft_strcpy(result, strs[0]);
	i = 1;
	while (i < size)
	{
		result = ft_strcat(result, sep);
		result = ft_strcat(result, strs[i]);
		i++;
	}
	return (result);
}
