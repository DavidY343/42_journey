/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:26:41 by david             #+#    #+#             */
/*   Updated: 2023/10/02 18:07:41 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_memory(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	free_leftovers(int *size, t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	free(size);
}
