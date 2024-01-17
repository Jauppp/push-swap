/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_stack_rules.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:20:48 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/12 15:46:20 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_node **a, t_node **b)
{
	ft_printf("ss\n");
	swap(a, 'c');
	swap(b, 'c');
}

void	rotate_ab(t_node **a, t_node **b)
{
	ft_printf("rr\n");
	rotate(a, 'c');
	rotate(b, 'c');
}

void	reverse_rotate_ab(t_node **a, t_node **b)
{
	ft_printf("rrr\n");
	reverse_rotate(a, 'c');
	reverse_rotate(b, 'c');
}
