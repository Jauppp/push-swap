/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_stack_rules.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:20:48 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/08 16:17:53 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_node **stack_a, t_node **stack_b)
{
	ft_printf("ss\n");
	swap(stack_a, 'c');
	swap(stack_b, 'c');
}

void	rotate_ab(t_node **stack_a, t_node **stack_b)
{
	ft_printf("rr\n");
	rotate(stack_a, 'c');
	rotate(stack_b, 'c');
}

void	reverse_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	ft_printf("rrr\n");
	reverse_rotate(stack_a, 'c');
	reverse_rotate(stack_b, 'c');
}
