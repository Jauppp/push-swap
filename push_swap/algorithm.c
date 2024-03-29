/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:11:30 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/19 17:06:35 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_small_stack(t_node **stack)
{
	ssize_t	len;

	len = get_list_len(*stack);
	while (--len > 0)
	{
		if ((*stack)->index == find_max(*stack))
			rotate(stack, 'a');
		else if ((*stack)->index > (*stack)->next->index)
			swap(stack, 'a');
		else if ((*stack)->next->index == find_max(*stack))
		{
			swap(stack, 'a');
			rotate(stack, 'a');
		}
	}
}

static void	sort_a_to_b(t_node **a, t_node **b, float chunk, size_t leftovers)
{
	const unsigned int	max = (find_max(*a) - leftovers);
	size_t				len;
	size_t				num;

	len = get_list_len(*a);
	num = 0;
	while (len > leftovers)
	{
		if ((*a)->index <= num && (*a)->index <= max)
			pb_and_increment(a, b, &len, &num);
		else if ((*a) && (*a)->index < (num + chunk) && (*a)->index <= max)
		{
			pb_and_increment(a, b, &len, &num);
			if ((*a)->index >= num && (*a)->index >= max)
				rotate_ab(a, b);
			else
				rotate(b, 'b');
		}
		else
			rotate(a, 'a');
	}
}

static void	sort_medium_stack(t_node **a, t_node **b)
{
	size_t			index;
	size_t			len;

	index = find_min(*a);
	len = get_list_len(*a);
	while (len > 3)
	{
		while ((*a)->index != index)
		{
			if (next_in_first_half(*a, index))
				rotate(a, 'a');
			else
				reverse_rotate(a, 'a');
		}
		if ((*a)->index == index)
		{
			push(b, a, 'b');
			index++;
			len--;
		}
	}
}

static void	sort_b_to_a(t_node **a, t_node **b)
{
	const size_t	max_a = find_max(*a);
	size_t			max_b;

	max_b = find_max(*b);
	while (*b || (*a)->prev->index != max_a)
	{
		if ((*a)->prev->index == ((*a)->index - 1))
			reverse_rotate(a, 'a');
		else if (bhead_can_be_pushed(a, b, max_a, max_b))
			push_bhead(a, b, &max_b);
		else if (next_in_first_half(*b, max_b))
		{
			if (both_stacks_need_rotate(a, b))
				rotate_ab(a, b);
			else
				rotate(b, 'b');
		}
		else
		{
			if (both_stacks_need_rotate(a, b))
				reverse_rotate_ab(a, b);
			else
				reverse_rotate(b, 'b');
		}
	}
}

void	get_chunk_and_sort(t_node **a, t_node **b)
{
	const size_t	nb_nodes = get_list_len(*a);
	float			chunk;

	if (nb_nodes <= S_LIST)
		chunk = (0.0000000053 * (nb_nodes * nb_nodes)) \
		+ (0.03 * nb_nodes) + S_CHUNK;
	if (nb_nodes > S_LIST && nb_nodes <= M_LIST)
		chunk = (0.0000000053 * (nb_nodes * nb_nodes)) \
		+ (0.03 * nb_nodes) + M_CHUNK;
	if (nb_nodes > M_LIST)
		chunk = (0.0000000053 * (nb_nodes * nb_nodes)) \
		+ (0.03 * nb_nodes) + L_CHUNK;
	if (nb_nodes > S_LIST)
	{
		sort_a_to_b(a, b, chunk, INTERMEDIATE_SORT);
		sort_medium_stack(a, b);
	}
	else
		sort_a_to_b(a, b, chunk, NO_INTERMEDIATE_SORT);
	sort_small_stack(a);
	if (!*b)
		return ;
	sort_b_to_a(a, b);
}
