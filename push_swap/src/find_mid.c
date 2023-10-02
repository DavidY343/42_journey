/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:48:07 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/02 16:18:26 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*copy_stack(t_stack *stack, int chunk)
{
	t_stack	*new_stack;
	t_stack	*temp;

	new_stack = NULL;
	while (stack != NULL)
	{
		if (stack->chunk == chunk)
		{
			temp = new_node(stack->n, stack->chunk);
			temp->next = new_stack;
			new_stack = temp;
		}
		stack = stack->next;
	}
	return (new_stack);
}

t_stack	*sorted_merge(t_stack *a, t_stack *b)
{
	t_stack	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->n <= b->n)
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return (result);
}

void	front_back_split(t_stack *src, t_stack **front_ref, t_stack **back_ref)
{
	t_stack	*fast;
	t_stack	*slow;

	slow = src;
	fast = src->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = src;
	*back_ref = slow->next;
	slow->next = NULL;
}

void	merge_sort(t_stack **head_ref)
{
	t_stack	*head;
	t_stack	*a;
	t_stack	*b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
	{
		return ;
	}
	front_back_split(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*head_ref = sorted_merge(a, b);
}

int	find_mid(t_stack *stack, int chunk)
{
	t_stack	*copy;
	t_stack	*slow_ptr;
	t_stack	*fast_ptr;
	int		mid_number;

	copy = copy_stack(stack, chunk);
	merge_sort(&copy);
	slow_ptr = copy;
	fast_ptr = copy;
	if (copy != NULL)
	{
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;
		}
	}
	mid_number = slow_ptr->n;
	free_stack(copy);
	return (mid_number);
}
