/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:23:36 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/27 19:49:59 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

char	*find(int key, t_node *list);
int		read_dict(char *file, t_node **list);
int		check_argc(int argc);
int		check_number(char *str);
void	free_list(t_node **list);

void	write_thousand(unsigned int num, t_node *list, int end)
{
	unsigned int	hundreds;
	unsigned int	tens;

	hundreds = num / 100;
	if (hundreds > 0)
	{
		ft_putstr(find(hundreds, list), 1);
		ft_putstr(find(100, list), 1);
		num -= hundreds * 100;
	}
	if (num >= 20)
	{
		tens = num / 10;
		if (tens > 0)
		{
			ft_putstr(find(tens * 10, list), 1 + end);
			num -= tens * 10;
		}
		if (num > 0)
			ft_putstr(find(num, list), 0 + end);
	}
	else if (num > 0)
		ft_putstr(find(num, list), 0 + end);
}

void	write_hundred_aux(unsigned int num, t_node *list)
{
	unsigned int	thousands;

	thousands = num / 1000;
	if (thousands > 0)
	{
		if (thousands >= 20)
			write_thousand(thousands, list, 1);
		else
			ft_putstr(find(thousands, list), 1);
		ft_putstr(find(1000, list), 1);
		num -= thousands * 1000;
	}
	write_thousand(num, list, 0);
}

void	write_hundred(unsigned int num, t_node *list)
{
	unsigned int	millions;

	if (num == 0)
	{
		ft_putstr(find(0, list), 1);
		return ;
	}
	if ((num / 1000000000) > 0)
	{
		ft_putstr(find((num / 1000000000), list), 1);
		ft_putstr(find(1000000000, list), 1);
		num -= (num / 1000000000) * 1000000000;
	}
	millions = num / 1000000;
	if (millions > 0)
	{
		if (millions >= 20)
			write_thousand(millions, list, 1);
		else
			ft_putstr(find(millions, list), 1);
		ft_putstr(find(1000000, list), 1);
		num -= millions * 1000000;
	}
	write_hundred_aux(num, list);
}

int	main(int argc, char **argv)
{
	char	*file;
	char	*number;
	t_node	*list;

	list = NULL;
	if (check_argc(argc) != 0)
		return (1);
	file = "numbers.dict";
	number = argv[1];
	if (argc == 3)
	{
		file = argv[1];
		number = argv[2];
	}
	if (check_number(number) != 0)
		return (1);
	if (read_dict(file, &list) == -1)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	write_hundred(ft_atoi(number), list);
	write(1, "\n", 1);
	free_list(&list);
	return (0);
}
