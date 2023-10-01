/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:14:34 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/01 16:51:29 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Función para rotar los elementos de la pila hacia arriba (rotate)
void	rotate(t_stack **stack)
{
	/*t_stack	*first;
	t_stack	*second;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	first = *top;
	second = first->next;
	while (second->next != NULL)
	{
		first = second;
		second = second->next;
	}
	first->next = NULL;
	second->next = *top;
	*top = second;*/
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
