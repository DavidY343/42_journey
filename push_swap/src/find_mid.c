/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:48:07 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/01 02:18:22 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*copy_stack(t_stack *original, int maxsize)
{
	t_stack *copy;
    t_stack *copy_head;
    t_stack *original_head;
	
	if (original == NULL || maxsize == 0)
		return (NULL);
	copy = malloc(sizeof(t_stack));
	copy_head = copy;
	original_head = original;
    while (original_head != NULL && (maxsize == -1 || maxsize > 0))
    {
        copy->n = original_head->n;
        if (original_head->next != NULL && (maxsize == -1 || maxsize > 1))
        {
            copy->next = malloc(sizeof(t_stack));
            copy = copy->next;
        }
        else
            copy->next = NULL;
        original_head = original_head->next;
        if (maxsize != -1)
            maxsize--;
    }

    return copy_head;
}


t_stack *sorted_merge(t_stack *a, t_stack *b)
{
    t_stack *result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    if (a->n <= b->n) {
        result = a;
        result->next = sorted_merge(a->next, b);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next);
    }

    return result;
}

void front_back_split(t_stack *source, t_stack **front_ref, t_stack **back_ref)
{
    t_stack *fast;
    t_stack *slow;

    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front_ref = source;
    *back_ref = slow->next;
    slow->next = NULL;
}

void merge_sort(t_stack **head_ref)
{
    t_stack *head = *head_ref;
    t_stack *a;
    t_stack *b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    front_back_split(head, &a, &b);

    merge_sort(&a);
    merge_sort(&b);

    *head_ref = sorted_merge(a, b);
}

int find_middle(t_stack *head)
{
    t_stack *slow_ptr = head;
    t_stack *fast_ptr = head;

    if (head != NULL) {
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
    }

    return slow_ptr->n;
}

int	find_mid(t_stack *stack, int maxsize)
{
	t_stack	*copy;
	int mid_number;

	copy = copy_stack(stack, maxsize);
	merge_sort(&copy);
	mid_number = find_middle(copy);
	free(copy);
	return (mid_number);
}