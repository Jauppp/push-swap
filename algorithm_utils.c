/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:04:38 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/08 16:01:08 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_node *stack)
{
	size_t			i;
	size_t			len;
	t_node			*head;
	unsigned int	max;

	head = stack;
	len = get_list_len(stack);
	i = -1;
	max = 0;
	while (++i < len)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	stack = head;
	return (max);
}

int	find_min(t_node *stack)
{
	size_t			i;
	size_t			len;
	t_node			*head;
	unsigned int	min;

	head = stack;
	len = get_list_len(stack);
	i = -1;
	min = INT_MAX;

	while (++i < len)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	stack = head;
	return (min);
}

void	get_index(t_node *stack)
{
	size_t			i;
	size_t			len;
	t_node			*head;
	unsigned int	index;

	len = get_list_len(stack);
	i = -1;
	index = 0;

	head = stack;
	while (++i < len)
	{
		if (head->data > stack->data)
			index++;
		stack = stack->next;
	}
	stack = head;
	stack->index = index;
}
