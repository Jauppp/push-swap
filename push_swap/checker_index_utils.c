/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:47:28 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/16 16:17:45 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_index(t_node **stack)
{
	const size_t	len = get_list_len(*stack);
	size_t			i;
	t_node			*head;

	i = -1;
	head = *stack;
	while (++i < len)
	{
		get_index(*stack);
		*stack = (*stack)->next;
	}
	*stack = head;
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
	stack->index = index;
	stack = head;
}
