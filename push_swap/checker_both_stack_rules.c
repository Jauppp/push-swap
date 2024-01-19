/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_both_stack_rules.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:20:48 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/19 14:45:19 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_swap_ab(t_node **a, t_node **b)
{
	checker_swap(a);
	checker_swap(b);
}

void	checker_rotate_ab(t_node **a, t_node **b)
{
	checker_rotate(a);
	checker_rotate(b);
}

void	checker_reverse_rotate_ab(t_node **a, t_node **b)
{
	checker_reverse_rotate(a);
	checker_reverse_rotate(b);
}
