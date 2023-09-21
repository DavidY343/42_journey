/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:33:48 by david             #+#    #+#             */
/*   Updated: 2023/09/21 08:50:28 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
        int     i;

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

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *result;
        int             total_len;
        int             i;
        int             j;

        i = -1;
        j = 0;
        if (s1 == 0 || s2 == 0)
                return (0);
        total_len = ft_strlen(s1) + ft_strlen(s2);
        result = (char *)malloc(sizeof(char) * (total_len + 1));
        if (!result)
                return (0);
        while (s1[++i] != '\0')
                result[i] = s1[i];
        while (s2[j] != '\0')
        {
                result[i] = s2[j];
                j++;
                i++;
        }
        result[i] = '\0';
        return (result);
}

size_t  ft_strlen(const char *str)
{
	size_t  len;

    len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return (len);
}

