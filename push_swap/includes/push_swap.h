/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:12:52 by david             #+#    #+#             */
/*   Updated: 2023/10/02 13:52:49 by dyanez-m         ###   ########.fr       */
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
	int				chunk;
}	t_stack;

//sort
void free_stack(t_stack *stack);
void free_memory(char **argv);
int size(t_stack *top);
int count_elements_supirior(t_stack *stack, int chunk, int mid);
int count_elements_minor(t_stack *stack, int chunk, int mid);
void	sort_three(t_stack **a);
int count_elements(t_stack *stack, int chunk);
int peek_chunk(t_stack *stack);
int is_sorted_asc(t_stack *stack, int chunk);
int is_sorted_desc(t_stack *stack, int chunk);
int peek_num(t_stack *head);
int peek_bottom(t_stack *top);
int	scan_through_a(t_stack **a, t_stack **b, int mid, int chunk);
void first_part(t_stack **a, t_stack **b, int chunk);
void	second_part(t_stack **a, t_stack **b, int chunk_size);
void	sort(t_stack **a, t_stack **b);

// find mid
t_stack	*copy_stack(t_stack *original, int chunk);
t_stack *sorted_merge(t_stack *a, t_stack *b);
void front_back_split(t_stack *source, t_stack **front_ref, t_stack **back_ref);
void merge_sort(t_stack **head_ref);
int find_middle(t_stack *head);
int	find_mid(t_stack *stack, int chunk);

// input_handler
void	decider(t_stack **a, t_stack **b, int size);
void 	print_stack(t_stack *a);
void	fill_stack(t_stack **stack, int *number, int size);
int		*check_inputs(int argc, char **argv, int *size);
int		*check_inputs_aux(char **argv, int i, int *size);
int		check_num(char *str);

// operations declarations
t_stack	*new_node(int n, int chunk);
int		pop(t_stack **top);
void	swap(t_stack **top);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **top, int n, int chunk);
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