/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:16:41 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/30 16:44:02 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	write_sol(char **matrix, int *row_col, int max, char fill);

int	find_sol(int **sol, int *row, int *col, int max)
{
	int	i;
	int	j;

	i = 0;
	while (i < *row)
	{
		j = 0;
		while (j < *col)
		{
			if (sol[i][j] == max)
			{
				*row = i + 1;
				*col = j + 1;
				return (max);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	get_min(int left, int up, int diagonal)
{
	int	min;

	min = left;
	if (up < min)
		min = up;
	if (diagonal < min)
		min = diagonal;
	return (min);
}

int	put_sol(int **sol, int *row, int *col)
{
	int	max;
	int	i;
	int	j;
	int	min;

	i = 1;
	max = 1;
	while (i < *row)
	{
		j = 1;
		while (j < *col)
		{
			if (sol[i][j] != 0)
			{
				min = get_min(sol[i - 1][j], sol[i][j - 1], sol[i - 1][j - 1]);
				sol[i][j] = min + 1;
				if (sol[i][j] > max)
					max = sol[i][j];
			}
			j++;
		}
		i++;
	}
	return (find_sol(sol, row, col, max));
}

void	free_sol(int **sol, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(sol[i]);
		i++;
	}
	free(sol);
}

void	translate_sol(char **matrix, int row, int col, char *buffer)
{
	int	**sol;
	int	i;
	int	j;
	int	max;
	int	row_col[2];

	i = -1;
	sol = (int **)malloc(sizeof(int *) * row);
	while (++i < row)
	{
		j = -1;
		sol[i] = (int *)malloc(sizeof(int) * col);
		while (++j < col)
		{
			if (matrix[i][j] == buffer[0])
				sol[i][j] = 1;
			if (matrix[i][j] == buffer[1])
				sol[i][j] = 0;
		}
	}
	max = put_sol(sol, &row, &col);
	row_col[0] = row;
	row_col[1] = col;
	write_sol(matrix, row_col, max, buffer[2]);
	free_sol(sol, row);
}
