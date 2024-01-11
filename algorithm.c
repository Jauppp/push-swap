/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:11:30 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/11 17:09:14 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_node **stack)
{
	ssize_t	len;

	len = get_list_len(*stack);
	while (len-- > 0)
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
	size_t			len;

	index = find_min(*stack_a);
	len = get_list_len(*stack_a);
	while (len > 3)
	{
		if ((*stack_a)->index != index)
		{
			if (!find_rotate_direction(*stack_a, index))
			{
				while ((*stack_a)->index != index)
					rotate(stack_a, 'a');
			}
			else
			{
				while ((*stack_a)->index != index)
				{
					reverse_rotate(stack_a, 'a');
				}
			}
		}
		else
		{
			push(stack_b, stack_a, 'b');
			index++;
			len--;
		}
	}
	sort_small_stack(stack_a);
	final_sort(stack_a, stack_b);
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	const size_t	nb_nodes = get_list_len(*stack_a);
	const float		chunk = (0.0000000053 * (nb_nodes * nb_nodes)) + \
						(0.03 * nb_nodes) + 14.5;

	pre_sort(stack_a, stack_b, chunk);
	sort_by_index(stack_a, stack_b);
	final_sort(stack_a, stack_b);
}


void	pre_sort(t_node **stack_a, t_node **stack_b, const float chunk)
{
	const unsigned int	max = (find_max(*stack_a) - 11);
	size_t				len;
	size_t				num;

	len = get_list_len(*stack_a);
	num = 0;
	while (len > 11)
	{
		if ((*stack_a)->index <= num && (*stack_a)->index <= max)
		{
			push(stack_b, stack_a, 'b');
			num++;
			len--;
		}
		else if ((*stack_a) && (*stack_a)->index < (num + chunk) \
			&& (*stack_a)->index <= max)
		{
			push(stack_b, stack_a, 'b');
			rotate(stack_b, 'b');
			num++;
			len--;
		}
		else
			rotate(stack_a, 'a');
	}
}

void	final_sort(t_node **stack_a, t_node **stack_b)
{
	unsigned int	max;

	max = find_max(*stack_b);
	while (*stack_b)
	{
		if ((*stack_b)->index == max)
		{
			push(stack_a, stack_b, 'a');
			max--;
		}
		if (!*stack_b)
			break ;
		if (!find_rotate_direction(*stack_b, max))
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
