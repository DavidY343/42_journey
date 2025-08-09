/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalah-d <lsalah-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:16:38 by lsalah-d          #+#    #+#             */
/*   Updated: 2023/08/27 19:44:49 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ft.h"

void	insert(unsigned int key, char *value, t_node **list)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->key = key;
	new_node->value = value;
	new_node->next = *list;
	*list = new_node;
}

char	*find(unsigned int key, t_node *list)
{
	t_node	*node;

	node = list;
	while (node != NULL)
	{
		if (key == node->key)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

void	free_list(t_node **list)
{
	t_node	*node;
	t_node	*next;

	node = *list;
	while (node != NULL)
	{
		next = node->next;
		free(node->value);
		free(node);
		node = next;
	}
	*list = NULL;
}
