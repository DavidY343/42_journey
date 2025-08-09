/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:52:37 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/28 15:52:41 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_stringcount(char *str, char *sep)
{
	int	i;
	int	counter;
	int	new_string;

	new_string = 1;
	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i], sep))
		{
			new_string = 1;
		}
		else
		{
			if (new_string == 1)
			{
				counter++;
				new_string = 0;
			}
		}
		i++;
	}
	return (counter);
}

char	*put_string(char *str, char *charset)
{
	int		len;
	char	*string;
	int		i;

	len = 0;
	i = 0;
	while (str[len] != '\0' && !is_separator(*(str + len), charset))
		len++;
	string = (char *)malloc(sizeof(char ) * (len + 1));
	while (i < len)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split_v2(char **sol, char *str, char *charset)
{
	int	i;
	int	new_string;

	new_string = 1;
	i = 0;
	while (*str != '\0')
	{
		if (is_separator(*str, charset))
		{
			new_string = 1;
		}
		else
		{
			if (new_string == 1)
			{
				sol[i] = put_string(str, charset);
				i++;
				new_string = 0;
			}
		}
		str++;
	}
	sol[i] = 0;
	return (sol);
}

char	**ft_split(char *str, char *charset)
{
	char	**sol;
	char	*copy;

	copy = str;
	sol = malloc(sizeof(char *) * ft_stringcount(copy, charset) + 1);
	sol = ft_split_v2(sol, copy, charset);
	return (sol);
}
