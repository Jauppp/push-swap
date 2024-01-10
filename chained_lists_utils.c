/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_lists_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:53:21 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/10 15:40:45 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_new(long data)
{
	t_node	*new_node;

	new_node = malloc(1 * sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

t_node	*append_back(t_node **stack, t_node	*new_node)
{
	if (!new_node)
		return (NULL);
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = *stack;
		new_node->next = *stack;
	}
	else
	{
		if ((*stack)->next == *stack)
			(*stack)->next = new_node;
		(*stack)->prev->next = new_node;
		new_node->prev = (*stack)->prev;
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	return (*stack);
}

t_node	*append_front(t_node **stack, t_node *new_node)
{
	if (!new_node)
		return (NULL);
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = *stack;
		new_node->next = *stack;
	}
	else
	{
		if ((*stack)->next == *stack)
			(*stack)->next = new_node;
		new_node->prev = (*stack)->prev;
		new_node->next = *stack;
		(*stack)->prev->next = new_node;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
	return (*stack);
}

t_node	*free_stack(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (stack_a && *stack_a)
	{
		(*stack_a)->prev->next = NULL;
		while (*stack_a)
		{
			temp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = temp;
		}
		*stack_a = NULL;
	}
	if (stack_b && *stack_b)
	{
		(*stack_b)->prev->next = NULL;
		while (*stack_b)
		{
			temp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = temp;
		}
		*stack_b = NULL;
	}
	return (NULL);
}

size_t	get_list_len(t_node *stack)
{
	size_t	i;
	t_node	*head;

	if (!stack)
		return (ERROR);
	i = 0;
	head = stack;
	while (stack->next != head)
	{
		i++;
		stack = stack->next;
	}
	stack = head;
	return (i + 1);
}
