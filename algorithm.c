/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:11:30 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/10 15:43:16 by cdomet-d         ###   ########lyon.fr   */
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
		if ((*stack)->index == find_max(*stack))
		{
			rotate(stack, 'a');
		}
		else if ((*stack)->index > (*stack)->next->index)
		{
			swap(stack, 'a');
		}
		else if ((*stack)->next->index == find_max(*stack))
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

void	sort(t_node **stack_a, t_node **stack_b)
{
	const size_t	nb_nodes = get_list_len(*stack_a);
	const float		chunk = (0.0000000053 * (nb_nodes * nb_nodes)) + (0.03 * nb_nodes) + 14.5;
	size_t			num;
	unsigned int	max;

	int secure = 0;

	num = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= num)
		{
			push(stack_b, stack_a, 'b');
			num++;
		}
		else if ((*stack_a) && (*stack_a)->index < (num + chunk))
		{
			push(stack_b, stack_a, 'b');
			rotate(stack_b, 'b');
			num++;
		}
		else
		{
			rotate(stack_a, 'a');
		}
		secure++;
	}
	max = find_max(*stack_b);
	while (*stack_b)
	{
		if ((*stack_b)->index == max)
		{
			push(stack_a, stack_b, 'a');
			max--;
		}
		if (*stack_b == NULL)
			break ;
		if (find_rotate_direction(*stack_b))
		{
			while ((*stack_b)->index != max)
				rotate(stack_b, 'b');
		}
		else
		{
			while ((*stack_b)->index != max)
				reverse_rotate(stack_b, 'b');
		}
	}
}
