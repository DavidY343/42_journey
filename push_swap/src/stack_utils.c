/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:36:54 by david             #+#    #+#             */
/*   Updated: 2023/10/02 16:33:22 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int n, int chunk)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->n = n;
	node->next = NULL;
	node->chunk = chunk;
	return (node);
}

void	fill_stack(t_stack **stack, int *number, int size)
{
	t_stack	*node;

	while (size--)
	{
		node = new_node(number[size], 0);
		if (!node)
			return ;
		node->next = *stack;
		*stack = node;
	}
}

// Función para eliminar un elemento de la pila (pop)
int	pop(t_stack **top)
{
	t_stack	*temp;
	int		n;

	if (*top == NULL)
		return (-1);
	n = (*top)->n;
	temp = *top;
	*top = (*top)->next;
	free(temp);
	return (n);
}
