/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:50:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/11 14:56:43 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	basic_korean_sort(t_node **stack_a, t_node **stack_b);

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (!argv[1])
		return (ERROR);
	stack_a = NULL;
	stack_b = NULL;
	if (!parsing(&stack_a, argc, argv))
		return (ERROR);
	sort(&stack_a, &stack_b);
	free_stack(&stack_a, &stack_b);
}
