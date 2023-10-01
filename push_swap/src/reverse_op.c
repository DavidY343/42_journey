/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:48:01 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/01 15:01:41 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Función para rotar los elementos de la pila hacia abajo (reverse rotate)
void	reverse_rotate(t_stack **top)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	last = *top;
	while (last->next != NULL)
		last = last->next;
	second_last = *top;
	while (second_last->next != last)
		second_last = second_last->next;
	last->next = *top;
	*top = last;
	second_last->next = NULL;
}

// Función para rotar los elementos de la pila hacia abajo (reverse rotate)
void	rra(t_stack **a)
{
	ft_printf("rra\n");
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	ft_printf("rrb\n");
	reverse_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}
