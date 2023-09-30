/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:12:52 by david             #+#    #+#             */
/*   Updated: 2023/09/30 19:33:28 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}	t_stack;

// find mid
t_stack *copy_stack(t_stack *original);
t_stack *sorted_merge(t_stack *a, t_stack *b);
void front_back_split(t_stack *source, t_stack **front_ref, t_stack **back_ref);
void merge_sort(t_stack **head_ref);
int find_middle(t_stack *head);
int	find_mid(t_stack *stack);

// input_handler
void 	print_stack(t_stack *a);
void	fill_stack(t_stack **stack, int *number, int size);
int		*check_inputs(int argc, char **argv, int *size);
int		*check_inputs_aux(char **argv, int i, int *size);
int		check_num(char *str);
t_stack *copy_stack(t_stack *original);

// operations declarations
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