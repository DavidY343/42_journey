/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:14:34 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/09/26 17:16:36 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// Función para rotar los elementos de la pila hacia arriba (rotate)
void	rotate(t_stack **top)
{
	t_stack	*first;
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
	*top = second;
}

// Función para rotar los elementos de la pila hacia arriba (rotate)
void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
