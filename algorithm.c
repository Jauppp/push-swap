/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:11:30 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/08 18:53:40 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_node **stack)
{
	size_t	len;
	size_t	i;

	i = -1;
	len = get_list_len(*stack);
	while (++i < len)
	{
		if ((*stack)->data == find_max(*stack))
			rotate(stack, 'a');
		if ((*stack)->data > (*stack)->next->data)
			swap(stack, 'a');
		if ((*stack)->next->data == find_max(*stack))
		{
			swap(stack, 'a');
			rotate(stack, 'a');
		}
	}
}

void	sort_by_index(t_node **stack_a, t_node **stack_b)
{
	unsigned int	index;

	index = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index != index)
			rotate(stack_a, 'a');
		else
		{
			push(stack_b, stack_a, 'b');
			index++;
		}
	}
	while (*stack_b)
		push(stack_a, stack_b, 'a');
}
