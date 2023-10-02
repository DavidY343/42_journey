/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:36:57 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/02 18:10:39 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*is_sorted_asc(*a, chunk) == 0 && esto para el if final del first part*/
void	first_part(t_stack **a, t_stack **b, int chunk)
{
	int	mid;
	int	ra_uses;

	while ((*a) != NULL && is_sorted_asc(*a, chunk) == 0)
	{
		mid = find_mid(*a, chunk);
		ra_uses = scan_through_a(a, b, mid, chunk);
		while (ra_uses > 0 && chunk != 0)
		{
			rra(a);
			ra_uses--;
		}
		if (count_elements(*a, chunk) == 2)
		{
			if ((*a)->n > (*a)->next->n)
				sa(a);
		}
	}
}

void	second_part(t_stack **a, t_stack **b, int chunk)
{
	int	mid;
	int	rb_uses;

	while (is_sorted_desc(*b, chunk) == 0 && is_sorted_asc(*a, -1) == 1)
	{
		mid = find_mid(*b, chunk);
		rb_uses = scan_through_b(a, b, mid, chunk);
		while (rb_uses > 0 && chunk != 0)
		{
			rrb(b);
			rb_uses--;
		}
		if (is_sorted_asc(*a, -1) == 1
			&& count_elements(*b, chunk) == 2 && *b != NULL)
		{
			(*b)->chunk = peek_chunk(*a) + 1;
			(*b)->next->chunk = peek_chunk(*a) + 1;
			pa(a, b);
			pa(a, b);
			if ((*a)->n > (*a)->next->n)
				sa(a);
		}
	}
}

/*void	first_lap(t_stack **a, t_stack **b)
{
	int	mid;
	int i;


	while (is_sorted_asc(*a, 0) == 0)
	{
		mid = find_mid(*a, 0);
		i = count_elements_minor(*a, 0, mid);
		while (i)
		{
			if (peek_num(*a) < mid)
			{
				pb(a, b);
				i--;
			}
			else
				ra(a);
		}
	}
	if (count_elements(*a, 0) == 2)
	{
		if ((*a)->n > (*a)->next->n)
			sa(a);
	}
}*/

//first_lap(a, b);
void	sort(t_stack **a, t_stack **b)
{
	int	chunk;

	while (is_sorted_asc(*a, 0) == 0 || *b != NULL)
	{
		chunk = peek_chunk(*a);
		first_part(a, b, chunk);
		chunk = peek_chunk(*b);
		second_part(a, b, chunk);
		while (is_sorted_desc(*b, chunk) == 1 && (*b) != NULL
			&& is_sorted_asc(*a, -1) == 1 && peek_chunk(*b) == chunk)
		{
			(*b)->chunk = peek_chunk(*a) + 1;
			pa(a, b);
		}
	}
}
