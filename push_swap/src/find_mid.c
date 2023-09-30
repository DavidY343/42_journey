/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:48:07 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/09/30 19:33:20 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *copy_stack(t_stack *original)
{
    if (original == NULL) {
        return (NULL);
    }

    t_stack *copy = malloc(sizeof(t_stack));
    copy->n = original->n;
    copy->next = copy_stack(original->next);
    return copy;
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
/*
t_stack *get_tail(t_stack *cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

t_stack *partition(t_stack *head, t_stack *end, t_stack **new_head, t_stack **new_end) {
    t_stack *pivot = end;
    t_stack *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->n < pivot->n) {
            if ((*new_head) == NULL)
                (*new_head) = cur;
            prev = cur;  
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;
            t_stack *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*new_head) == NULL)
        (*new_head) = pivot;

    (*new_end) = tail;

    return pivot;
}

t_stack *quick_sort_recur(t_stack *head, t_stack *end) {
    if (!head || head == end)
        return head;

    t_stack *new_head = NULL, *new_end = NULL;

    t_stack *pivot = partition(head, end, &new_head, &new_end);

    if (new_head != pivot) {
        t_stack *tmp = new_head;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        new_head = quick_sort_recur(new_head, tmp);

        tmp = get_tail(new_head);
        tmp->next =  pivot;
    }

    pivot->next = quick_sort_recur(pivot->next, new_end);

    return new_head;
}

void quick_sort(t_stack **head_ref) {
    (*head_ref) = quick_sort_recur(*head_ref, get_tail(*head_ref));
    return;
}*/

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

int	find_mid(t_stack *stack)
{
	t_stack	*copy;
	int mid_number;

	copy = copy_stack(stack);
	merge_sort(&copy);
	mid_number = find_middle(copy);
	free(copy);
	return (mid_number);
}