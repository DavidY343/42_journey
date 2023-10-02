/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:38:24 by david             #+#    #+#             */
/*   Updated: 2023/10/02 16:31:20 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	decider(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else
		sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		*nbr;

	size = 0;
	a = NULL;
	b = NULL;
	nbr = check_inputs(argc, argv, &size);
	fill_stack(&a, nbr, size);
	if (!is_sorted_asc(a, 0))
		decider(&a, &b, size);
	free_leftovers(nbr, a, b);
}
