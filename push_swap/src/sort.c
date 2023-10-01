/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:36:57 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/01 01:34:40 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	scan_through_a(t_stack **a, t_stack **b, int mid, int size)
{
	int	counter;

	counter = 0;
	while (size)
	{
		if ((*a)->n < mid)
		{
			pb(a, b);
			counter++;
		}
		else if (peekBottom(*a) < mid)
		{
			rra(a);
			pb(a, b);
			counter++;
		}
		else
			ra(a);
		size--;
	}
	return (counter);
}

int	*first_part(t_stack **a, t_stack **b, int log_size, int size)
{
	int	mid;
	int	*chunk;
	int i;

	i = 0;
	chunk = (int *)malloc(sizeof(int) * log_size);
	while (log_size > 0)
	{
		mid = find_mid(*a, -1);
		ft_printf("mid = %d\n", mid);
		chunk[i++] = scan_through_a(a, b, mid, size);
		log_size--;
		print_stack(*a);
		ft_printf("----\n");
		print_stack(*b);
		size /= 2;
	}
	if ((*a)->n > (*a)->next->n)
		sa(a);
	return (chunk);
}

int	move_chunk(t_stack **a, t_stack **b, int chunk_size, int mid)
{
	int	i;
	int	rb_count;
	int	pa_uses;

	pa_uses = 0;
	rb_count = 0;
	i = 0;
	while (i < chunk_size)
	{
		if ((*b)->n > mid)
		{
			pa(a, b);
			i++;
			pa_uses++;
		}
		else
		{
			rb(b);
			rb_count++;
		}
	}
	while (rb_count > 0)
	{
		rrb(b);
		rb_count--;
	}
	return (pa_uses);
}

void	second_part(t_stack **a, t_stack **b, int chunk_size)
{
	int mid;
	int pa_uses;

	if (chunk_size <= 2 || is_sorted_desc(*b, chunk_size) == 1)
	{
		if ((*b)->n < ((*b)->next->n))
			sb(b);
		pa(a, b);
		pa(a, b);
		if ((*a)->n > (*a)->next->n)
			sa(a);
		return ;
	}
	mid = find_mid(*b, chunk_size);
	pa_uses = move_chunk(a, b, chunk_size, mid);
	mid = find_mid(*a, pa_uses);
	scan_through_a(a, b, mid, pa_uses);
	print_stack(*a);
	ft_printf("----\n");
	print_stack(*b);
	if (chunk_size - pa_uses <= 2 || is_sorted_desc(*b, chunk_size) == 1)
        return ;  // Agregamos una condición de salida aquí
	return (second_part(a, b, chunk_size - pa_uses));
}

void	sort(t_stack **a, t_stack **b, int size)
{
	int log_size;
	int	*chunk;

	ft_printf("size = %d\n", size);
		
	log_size = divider(size);
	ft_printf("log_size = %d\n", log_size);
	chunk = first_part(a, b, log_size, size);
	print_stack(*a);
	ft_printf("----\n");
	for (int i = 0; i < log_size; i++)
		ft_printf("chunk en orden= %d\n", chunk[i]);
	while (log_size > 0)
	{
		print_stack(*b);
		ft_printf("chunk = %d\n", chunk[log_size - 1]);
		second_part(a, b, chunk[--log_size]);
	}
	free(chunk);
	
}

