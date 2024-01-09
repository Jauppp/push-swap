/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:13:16 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/09 17:16:40 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_stack(t_node **stack_a, char *arg)
{
	t_node	*new_node;

	if (!*arg)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (NULL);
	}
	while (*arg)
	{
		while (!ft_isdigit_negative(*arg))
			arg++;
		new_node = stack_new(ft_atoi_intmax(arg));
		if (!new_node)
			return (free_stack(stack_a, NULL));
		*stack_a = append_back(stack_a, new_node);
		while (ft_isdigit_negative(*arg))
			arg++;
	}
	return (*stack_a);
}

t_node	*parsing(t_node **stack, size_t argc, char *argv[])
{
	size_t		i;
	size_t		j;

	i = -1;
	j = 0;
	while (++i < argc - 1)
	{
		if (check_invalid_charset(argv[++j]))
			return (NULL);
		if (!init_stack(stack, argv[j]))
			return (NULL);
	}
	if (!check_invalid_values(*stack))
		return (NULL);
	init_index(stack);
	return (*stack);
}


