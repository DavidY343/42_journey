/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:46:55 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/02 15:39:17 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Función para añadir un elemento a la pila (push)
void	push(t_stack **top, int n, int chunk)
{
	t_stack	*node;

	node = new_node(n, chunk);
	node->next = *top;
	*top = node;
}

// Función para mover el primer elemento de b a a (push a)
void	pa(t_stack **a, t_stack **b)
{
	if (*b == NULL)
		return ;
	ft_printf("pa\n");
	push(a, (*b)->n, peek_chunk(*b));
	pop(b);
}

// Función para mover el primer elemento de a a b (push b)
void	pb(t_stack **a, t_stack **b)
{
	if (*a == NULL)
		return ;
	ft_printf("pb\n");
	push(b, (*a)->n, peek_chunk(*a));
	pop(a);
}
