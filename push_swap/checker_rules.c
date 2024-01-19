/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:20:52 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/19 14:42:22 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_push(t_node **to, t_node **from)
{
	t_node	*new_head;

	if (!*from)
		return ;
	new_head = (*from)->next;
	if (new_head == *from)
	{
		append_front(to, *from);
		*from = NULL;
	}
	else
	{
		(*from)->prev->next = (*from)->next;
		(*from)->next->prev = (*from)->prev;
		append_front(to, *from);
		*from = new_head;
	}
}

void	checker_swap(t_node **stack)
{
	t_node	*node_2;

	if (!(*stack) || (*stack)->next == *stack)
		return ;
	if (get_list_len(*stack) == 2)
	{
		(*stack)->next = *stack;
		(*stack)->prev = *stack;
		*stack = (*stack)->next;
	}
	else
	{
		node_2 = (*stack)->next;
		(*stack)->next = node_2->next;
		node_2->prev = (*stack)->prev;
		(*stack)->next->prev = *stack;
		node_2->prev->next = node_2;
		(*stack)->prev = node_2;
		node_2->next = *stack;
		(*stack) = node_2;
	}
}

void	checker_rotate(t_node **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	checker_reverse_rotate(t_node **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}
