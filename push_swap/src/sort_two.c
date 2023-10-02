/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:05:36 by david             #+#    #+#             */
/*   Updated: 2023/10/02 20:53:43 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	while (is_sorted_asc(*a, 0) == 0)
	{
		if ((*a)->n > (*a)->next->n && (*a)->n < (*a)->next->next->n)
			sa(a);
		else
			ra(a);
	}
}

void	scan_through_a_top(t_stack **a, t_stack **b, int new_chunk, int *i)
{
	(*a)->chunk = new_chunk;
	pb(a, b);
	(*i)--;
}

void	scan_through_a_bottom(t_stack **a, t_stack **b, int new_chunk, int *i)
{
	rra(a);
	(*a)->chunk = new_chunk;
	pb(a, b);
	(*i)--;
}

int	scan_through_a(t_stack **a, t_stack **b, int mid, int chunk)
{
	int	ra_uses;
	int	new_chunk;
	int	i;

	i = count_elements_minor(*a, chunk, mid);
	new_chunk = 0;
	ra_uses = 0;
	if (*b != NULL)
		new_chunk = peek_chunk(*b) + 1;
	while (i > 0)
	{
		if (peek_num(*a) < mid)
			scan_through_a_top(a, b, new_chunk, &i);
		else if (peek_bottom(*a) < mid)
			scan_through_a_bottom(a, b, new_chunk, &i);
		else
		{
			ra(a);
			ra_uses++;
		}
	}
	return (ra_uses);
}

int	scan_through_b(t_stack **a, t_stack **b, int mid, int chunk)
{
	int	rb_uses;
	int	new_chunk;
	int	i;

	new_chunk = 0;
	rb_uses = 0;
	i = count_elements_supirior(*b, chunk, mid);
	if (*a != NULL)
		new_chunk = peek_chunk(*a) + 1;
	while (i)
	{
		if (peek_num(*b) > mid)
		{
			(*b)->chunk = new_chunk;
			pa(a, b);
			i--;
		}
		else
		{
			rb(b);
			rb_uses++;
		}
	}
	return (rb_uses);
}
