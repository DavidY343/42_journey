/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:01:01 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/01 01:16:05 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_sorted_asc(t_stack *stack, int maxsize)
{
    if (stack == NULL || maxsize == 0)
        return 1;  // Un stack vacío o maxsize 0 se considera ordenado
    t_stack *current = stack;
    t_stack *next = stack->next;
    int count = 1;  // Inicializamos el contador a 1, ya que tenemos al menos un elemento
    while (next != NULL && (maxsize == -1 || count < maxsize))
    {
        if (current->n > next->n)
            return 0;  // El stack no está ordenado en orden ascendente
        current = next;
        next = next->next;
        count++;
    }
    return 1;  // El stack está ordenado en orden ascendente
}

int is_sorted_desc(t_stack *stack, int maxsize)
{
    if (stack == NULL || maxsize == 0)
        return 1;  // Un stack vacío o maxsize 0 se considera ordenado
    t_stack *current = stack;
    t_stack *next = stack->next;
    int count = 1;  // Inicializamos el contador a 1, ya que tenemos al menos un elemento
    while (next != NULL && (maxsize == -1 || count < maxsize))
    {
        if (current->n < next->n)
            return 0;  // El stack no está ordenado en orden descendente
        current = next;
        next = next->next;
        count++;
    }
    return 1;  // El stack está ordenado en orden descendente
}

int peek(t_stack *head) {
    if (head == NULL) {
        ft_printf("La pila está vacía.\n");
        return -1; // O cualquier otro valor que indique que la pila está vacía
    }

    return head->n;
}

int peekBottom(t_stack *top) {
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

int size(t_stack *top) {
    int count = 0;
    t_stack *current = top;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int	divider(int size)
{
	int i;

	i = 0;
	if (size % 2 != 0)
		i++;
	while (size > 2)
	{
		size /= 2;
		i++;
	}

	return (i);
}
