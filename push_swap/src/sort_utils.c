/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:01:01 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/02 17:38:44 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted_asc(t_stack *stack, int chunk)
{
	int	min_num;

	min_num = -2147483648;
	while (stack != NULL)
	{
		if (peek_chunk(stack) == chunk || chunk == -1)
		{
			if (peek_num(stack) < min_num)
				return (0);
			min_num = peek_num(stack);
		}
		stack = stack->next;
	}
	return (1);
}

int	is_sorted_desc(t_stack *stack, int chunk)
{
	int	max_num;

	max_num = 2147483647;
	while (stack != NULL)
	{
		if (peek_chunk(stack) == chunk || chunk == -1)
		{
			if (peek_num(stack) > max_num)
				return (0);
			max_num = peek_num(stack);
		}
		stack = stack->next;
	}
	return (1);
}

int	count_elements(t_stack *stack, int chunk)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = stack;
	while (temp != NULL)
	{
		if (peek_chunk(temp) == chunk)
			count++;
		temp = temp->next;
	}
	return (count);
}

int	count_elements_minor(t_stack *stack, int chunk, int mid)
{
	int		count;
	t_stack	*temp;

	temp = stack;
	count = 0;
	while (temp != NULL)
	{
		if (peek_chunk(temp) == chunk && peek_num(temp) < mid)
			count++;
		temp = temp->next;
	}
	return (count);
}

int	count_elements_supirior(t_stack *stack, int chunk, int mid)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = stack;
	while (temp != NULL)
	{
		if (peek_chunk(temp) == chunk && peek_num(temp) > mid)
			count++;
		temp = temp->next;
	}
	return (count);
}
