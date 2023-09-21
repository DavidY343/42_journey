/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:33:48 by david             #+#    #+#             */
/*   Updated: 2023/09/21 14:07:10 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (0);
	while (s1[++i] != '\0')
		result[i] = s1[i];
	while (s2[++j] != '\0')
		result[i++] = s2[j];
	result[i] = '\0';
	free(s1);
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = (void *)malloc(size * nmemb);
	if (array != NULL)
		ft_bzero(array, nmemb * size);
	return (array);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*aux;
	int				i;

	i = 0;
	aux = s;
	while (n > 0)
	{
		aux[i] = '\0';
		n--;
		i++;
	}
}
