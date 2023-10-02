/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chill_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:01:07 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/01 22:24:04 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_till_three(t_stack **a, t_stack **b)
{
	int	i;
	t_stack	*top;
	while (size(*a) > 3 && is_sorted_asc(*a, 0) == 0)
	{
		top = *a;
		i = 
	}
}
void	sort(t_stack **a, t_stack **b)
{
	if (is_sorted_asc(*a, 0) == 0)
	{
		pb(a, b);
		pb(a, b);
	}
	if (is_sorted_asc(*a, 0) == 0 && size(*a) > 3)
		sort_till_three(a, b);
	if (is_sorted_asc(*a, 0) == 0)
		sort_three(a);
}