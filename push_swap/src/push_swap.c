/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:38:24 by david             #+#    #+#             */
/*   Updated: 2023/09/30 19:46:04 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *a)
{
	t_stack *temp;

	temp = a;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->n);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		*nbr;

	size = 0;
	a = NULL;
	nbr = check_inputs(argc, argv, &size);
	fill_stack(&a, nbr, size);
	sort(&a, &b, size);
	print_stack(a);

	free(nbr);
}