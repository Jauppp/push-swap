/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:50:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/09 10:19:45 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	// int		max;
	// int		min;

	stack_a = NULL;
	stack_b = NULL;
	if (!parsing(&stack_a, argc, argv))
		return (ERROR);
	// print_stack(stack_a, stack_b);
	sort_by_index(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	free_stack(&stack_a, &stack_b);
}
