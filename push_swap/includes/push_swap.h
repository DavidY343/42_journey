/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:12:52 by david             #+#    #+#             */
/*   Updated: 2023/09/28 16:24:23 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"

int	check_inputs(int argc, char **argv);

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}	t_stack;

t_stack	*new_node(int n);
int		pop(t_stack **top);
void	swap(t_stack **top);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **top, int n);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **top);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **top);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif