/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:36:54 by david             #+#    #+#             */
/*   Updated: 2023/10/02 17:38:16 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	peek_chunk(t_stack *stack)
{
	if (stack == NULL)
		return (-1);
	return (stack->chunk);
}

int	peek_num(t_stack *stack)
{
	if (stack == NULL)
		return (-1);
	return (stack->n);
}

int	peek_bottom(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (temp == NULL)
		return (-1);
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		return (temp->n);
	}
}
