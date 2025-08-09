/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:51:21 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/15 18:13:50 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	pos1;
	int	pos2;

	pos2 = 0;
	pos1 = 0;
	if (to_find[pos2] == '\0')
		return (str);
	while (str[pos1] != '\0')
	{
		pos2 = 0;
		while (str[pos1 + pos2] != '\0' && str[pos1 + pos2] == to_find[pos2])
			pos2++;
		if (to_find[pos2] == '\0')
			return (str + pos1);
		pos1++;
	}
	return (0);
}
