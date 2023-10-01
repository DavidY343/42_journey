/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:01:01 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/01 18:02:33 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_sorted_asc(t_stack *stack, int chunk)
{
	int last_num = -2147483648; 
	while (stack != NULL)
	{
		if (stack->chunk == chunk)
		{
			if (stack->n < last_num)
				return 0; 
			last_num = stack->n;
		}
		stack = stack->next;
	}
	return 1;
}

int is_sorted_desc(t_stack *stack, int chunk)
{
	int last_num = 2147483647; 
	while (stack != NULL)
	{
		if (stack->chunk == chunk)
		{
			if (stack->n > last_num)
				return 0;
			last_num = stack->n;
		}
		stack = stack->next;
	}
	return 1; 
}

int peek_chunk(t_stack *stack)
{
	if (stack == NULL)
		return (-1);
	return stack->chunk;
}

int peek_num(t_stack *head) {
    if (head == NULL) {
        ft_printf("La pila está vacía.\n");
        return -1; // O cualquier otro valor que indique que la pila está vacía
    }

    return head->n;
}

int peek_bottom(t_stack *top) {
    t_stack *current = top;
    if(current == NULL) {
        ft_printf("Stack Underflow\n");
        return -1;
    } else {
        while(current->next != NULL) {
            current = current->next;
        }
        return current->n;
    }
}

int count_elements(t_stack *stack, int chunk)
{
	int count = 0;
	t_stack *temp = stack;

	while (temp != NULL)
	{
		if (temp->chunk == chunk)
		{
			count++;
		}
		temp = temp->next;
	}
	return count;
}

int count_elements_minor(t_stack *stack, int chunk, int mid)
{
	int count = 0;
	t_stack *temp = stack;

	while (temp != NULL)
	{
		if (temp->chunk == chunk && peek_num(temp) < mid)
		{
			count++;
		}
		temp = temp->next;
	}
	return count;
}

int count_elements_supirior(t_stack *stack, int chunk, int mid)
{
	int count = 0;
	t_stack *temp = stack;

	while (temp != NULL)
	{
		if (temp->chunk == chunk && peek_num(temp) > mid)
		{
			count++;
		}
		temp = temp->next;
	}
	return count;
}


