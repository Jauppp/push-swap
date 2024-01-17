/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:20:52 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/17 18:04:27 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **to, t_node **from, int c)
{
	t_node	*new_head;

	if (!*from)
		return ;
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
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

void	swap(t_node **stack, int c)
{
	t_node	*node_2;

	if (!(*stack) || (*stack)->next == *stack)
		return ;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
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

void	rotate(t_node **stack, int c)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
	*stack = (*stack)->next;
}

void	reverse_rotate(t_node **stack, int c)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
	*stack = (*stack)->prev;
}
