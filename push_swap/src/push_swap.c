/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:38:24 by david             #+#    #+#             */
/*   Updated: 2023/10/01 18:00:13 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *a)
{
	t_stack *temp;

	temp = a;
	while (temp != NULL)
	{
		ft_printf("n = %d chunk = %d\n", temp->n, temp->chunk);
		temp = temp->next;
	}
}

void sort_three(t_stack **a)
{
    while (is_sorted_asc(*a, 0) == 0)
	{
		if ((*a)->n > (*a)->next->n && (*a)->n < (*a)->next->next->n)
			sa(a);
		else
			ra(a);
	}
}

void	decider(t_stack **a, t_stack **b, int size)
{
	if (size == 3)
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
	decider(&a, &b, size);
	free(nbr);
}