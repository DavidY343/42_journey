/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:47:10 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/23 18:08:15 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	contador;

	contador = 0;
	while (str[contador] != '\0' )
	{
		contador++;
	}
	return (contador);
}

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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (0);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	tab[i].copy = 0;
	return (tab);
}
