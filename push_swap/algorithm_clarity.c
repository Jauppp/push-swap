/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_clarity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:46:30 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/19 17:04:00 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_and_increment(t_node **a, t_node **b, size_t *len, size_t *num)
{
	push(b, a, 'b');
	(*num)++;
	(*len)--;
}

int	bhead_can_be_pushed(t_node **a, t_node **b, size_t max_a, size_t max_b)
{
	if (!*a || !*b)
		return (SUCCESS);
	if (((*b)->index == max_b || (*a)->prev->index == max_a) || \
		(*b)->index > (*a)->prev->index)
		return (ERROR);
	else
		return (SUCCESS);
}

void	push_bhead(t_node **a, t_node **b, size_t *max_b)
{
	push(a, b, 'a');
	if ((*a)->index != ((*a)->next->index - 1))
		rotate(a, 'a');
	(*max_b) = find_max(*b);
}

int	both_stacks_need_rotate(t_node **a, t_node **b)
{
	if (*b && (*b)->index < (*a)->prev->index && (*a)->index != \
		(*a)->next->index - 1)
		return (ERROR);
	else
		return (SUCCESS);
}
