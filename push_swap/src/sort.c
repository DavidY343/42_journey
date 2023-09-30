/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:36:57 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/09/30 20:33:20 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int peek(t_stack *head) {
    if (head == NULL) {
        printf("La pila está vacía.\n");
        return -1; // O cualquier otro valor que indique que la pila está vacía
    }

    return head->n;
}

t_stack *peekBottom(t_stack *top) {
    t_stack *current = top;
    if(current == NULL) {
        ft_printf("Stack Underflow\n");
        return NULL;
    } else {
        while(current->next != NULL) {
            current = current->next;
        }
        return current;
    }
}

void	scan_through(t_stack *a, t_stack *b, int mid)
{
	if (a->n < mid)
		pb(&a, &b);
	else if ()
}
void	sort(t_stack **a, t_stack **b, int size)
{
	int	mid;

	mid	= find_mid(*a);
	scan_through(*a, *b, mid);
}