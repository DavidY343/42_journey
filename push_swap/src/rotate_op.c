/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:14:34 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/02 16:32:05 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Función para rotar los elementos de la pila hacia arriba (rotate)
void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*iter;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	iter = *stack;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = tmp;
	tmp->next = NULL;
}

// Función para rotar los elementos de la pila hacia arriba (rotate)
void	ra(t_stack **a)
{
	ft_printf("ra\n");
	rotate(a);
}

void	rb(t_stack **b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}
