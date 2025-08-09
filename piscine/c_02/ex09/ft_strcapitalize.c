/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:11:35 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/14 16:20:03 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	p;

	p = 0;
	while (str[p] != '\0')
	{
		if (str[p] >= 'A' && str[p] <= 'Z')
			str[p] = str[p] + 32;
		p++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	pos;
	int	new_word;

	pos = 0;
	new_word = 1;
	ft_strlowcase(str);
	while (str[pos] != '\0')
	{
		if ((str[pos] >= 'a' && str[pos] <= 'z')
			|| (str[pos] >= 'A' && str[pos] <= 'Z')
			|| (str[pos] >= '0' && str[pos] <= '9'))
		{
			if (new_word == 1)
				if (str[pos] >= 'a' && str[pos] <= 'z')
					str[pos] -= 32;
				new_word = 0;
		}
		else
		{
			new_word = 1;
		}
		pos++;
	}
	return (str);
}
