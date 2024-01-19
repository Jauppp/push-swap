/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:13:16 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/19 13:37:46 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*init_stack(t_node **stack_a, char *arg)
{
	t_node	*new_node;
	size_t	i;

	i = 0;
	while (arg[i])
	{
		while (arg[i] && !ft_isdigit_negative(arg[i]))
			i++;
		if (arg[i])
			new_node = stack_new(ft_atoi_intmax(&arg[i]));
		if (!new_node)
			return (NULL);
		*stack_a = append_back(stack_a, new_node);
		while (arg[i] && ft_isdigit_negative(arg[i]))
			i++;
	}
	return (*stack_a);
}

t_node	*parse_and_init_stack(t_node **stack, size_t argc, char *argv[])
{
	size_t		i;
	size_t		j;

	i = -1;
	j = 1;
	while (++i < argc - 1)
	{
		if (arg_is_empty(argv[j]))
			return (free_stack(stack, NULL));
		if (arg_is_not_digit(argv[j]))
			return (free_stack(stack, NULL));
		if (!init_stack(stack, argv[j]))
			return (free_stack(stack, NULL));
		j++;
	}
	if (data_is_invalid(*stack))
		return (free_stack(stack, NULL));
	init_index(stack);
	return (*stack);
}
