/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:35:17 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/01 15:02:40 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **top)
{
	t_stack	*first;
	t_stack	*second;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	first = *top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*top = second;
}

void	sa(t_stack **a)
{
	ft_printf("sa\n");
	swap(a);
}

void	sb(t_stack **b)
{
	ft_printf("sb\n");
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}
