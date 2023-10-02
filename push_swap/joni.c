#include "psw.h"

int	count_group(t_stack *stack, int group)
{
	t_node	*node;
	int		size;

	node = stack->node;
	size = 0;
	while (node != NULL)
	{
		if (node->group == group)
			size++;
		node = node->next;
	}
	return (size);
}

int	check(t_stack *stack, int group, int op)
{
	t_node	*node;

	node = stack->node;
	if (node == NULL)
		return (0);
	if (op == -1)
	{
		while (node->next != NULL)
		{
			if (node->value > node->next->value)
				return (-1);
			node = node->next;
		}
	}
	else if (op == 0)
	{
		while (node->next != NULL)
		{
			if (node->value > node->next->value && node->next->group == group)
				return (-1);
			node = node->next;
		}
	}
	else
	{
		while (node->next != NULL)
		{
			if ((node->value < node->next->value) && (node->next->group == group))
				return (-1);
			node = node->next;
		}
	}
	return (0);
}

void	sort3_a(t_stack *stack)
{
	while (check(stack, 0, -1) == -1)
	{
		if (stack->node->value > stack->node->next->value && stack->node->value < stack->node->next->next->value)
			sa(&stack);
		else
			ra(&stack);
	}
}

/*static int	get_mid(t_stack *stack, int group)
{
	t_node	*node;
	int		total;

	total = 0;
	node = stack->node;
	while (node != NULL && node->group == group)
	{
		total += node->value;
		node = node->next;
	}
	if ((total % count_group(stack, group)) > count_group(stack, group) / 2)
		return ((total/count_group(stack, group)) + 1);
	return (total/count_group(stack, group));
}*/

static int	get_mid(t_stack *stack, int group)
{
	t_node	*node;
	int		big;
	int		small;

	node = stack->node;
	big = node->value;
	small = node->value;
	while (node != NULL && node->group == group)
	{
		if (node->value > big)
			big = node->value;
		if (node->value < small)
			small = node->value;
		node = node->next;
	}
	while (small < big - 1)
	{
		small++;
		big--;
	}
	return (small);
}

int	move_to_b(t_stack *a, t_stack *b, int middle, int group)
{
	int	init;
	int	group_b;

	init = 0;
	group_b = 0;
	if (b->node != NULL)
		group_b = b->node->group + 1;
	while (init < count_group(a, group) && a->node->group == group)
	{
		if (a->node->value <= middle)
		{
			a->node->group = group_b;
			pb(&a, &b);	
		}
		else
		{
			ra(&a);
			init++;
		}
	}
	return (init);
}

int	move_to_a(t_stack *a, t_stack *b, int middle, int group)
{
	int	init;
	int	group_a;

	init = 0;
	group_a = 0;
	if (a->node != NULL)
		group_a = a->node->group + 1;
	while (init < count_group(b, group) && b->node->group == group)
	{
		if (b->node->value > middle)
		{
			b->node->group = group_a;
			pa(&a, &b);
		}
		else
		{
			rb(&b);
			init++;
		}
	}
	return (init);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	int	middle;
	int	group;
	int	group_aux;
	int	recover;

	group = a->node->group;
	group_aux = 0;
	if (a->size == 3)
		sort3_a(a);
	while (check(a, 0, -1) == -1 || b->node != NULL)
	{
		group = a->node->group;
		recover = 0;
		while (a->node != NULL && check(a, group, 0) == -1)
		{
			middle = get_mid(a, group);
			recover = move_to_b(a, b, middle, group);
			while (group != 0 && recover > 0)
			{
				rra(&a);
				recover--;
			}
			if (count_group(a, group) == 2)
			{
				if (a->node->value > a->node->next->value)
					sa(&a);
			}
		}
		group = b->node->group;
		while (b->node != NULL && check(b, group, 1) == -1 && check(a, 0, -1) == 0)
		{
			middle = get_mid(b, group);
			recover = move_to_a(a, b, middle, group);
			while (group != 0 && recover > 0)
			{
				rrb(&b);
				recover--;
			}
			if (b->node != NULL && count_group(b, group) == 2  && check(a, 0, -1) == 0)
			{
				if (a->node != NULL)
					group_aux = a->node->group + 1;
				b->node->group = group_aux;
				b->node->next->group = group_aux;
				pa(&a, &b);
				pa(&a, &b);
				if (a->node->value > a->node->next->value)
					sa(&a);
			}
		}
		while (b->node != NULL && check(a, 0, -1) == 0 && check(b, group, 1) == 0 && b->node->group == group)
		{
			if (a->node != NULL)
				group_aux = a->node->group + 1;
			b->node->group = group_aux;
			pa(&a, &b);
		}
	}
}