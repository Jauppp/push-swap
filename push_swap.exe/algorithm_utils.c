/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:04:38 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/16 17:13:43 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	find_max(t_node *stack)
{
	size_t			i;
	size_t			len;
	t_node			*head;
	unsigned int	max;

	if (!stack)
		return (ERROR);
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

unsigned int	find_min(t_node *stack)
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

int	next_in_first_half(t_node *stack, unsigned int goal)
{
	size_t			i;
	size_t			len;
	t_node			*head;

	i = -1;
	len = get_list_len(stack);
	head = stack;
	while (++i < (len / 2))
	{
		if (stack->index == goal)
		{
			stack = head;
			return (ERROR);
		}
		stack = stack->next;
	}
	stack = head;
	return (SUCCESS);
}

int	list_not_sorted(t_node *stack)
{
	t_node			*head;

	head = stack;
	while (stack->next != head)
	{
		if (stack->index > stack->next->index)
		{
			stack = head;
			return (ERROR);
		}
		stack = stack->next;
	}
	stack = head;
	return (SUCCESS);
}
