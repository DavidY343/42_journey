/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:03:42 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/30 16:43:59 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_sol(char **matrix, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			write(1, &matrix[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void	write_sol(char **matrix, int *row_col, int max, char fill)
{
	int	i;
	int	j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			matrix[row_col[0] - max + i][row_col[1] - max + j] = fill;
			j++;
		}
		i++;
	}
}
