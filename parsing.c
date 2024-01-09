/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:13:16 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/08 18:43:10 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_stack(t_node **stack_a, char *arg)
{
	t_node	*new_node;
	t_node	*head;
	size_t	len;
	size_t	i;

	while (*arg)
	{
		while (!is_neg_digit(*arg))
			arg++;
		new_node = stack_new(ft_atoi(arg));
		if (!new_node)
			return (free_stack(stack_a, NULL));
		*stack_a = append_back(stack_a, new_node);
		while (is_neg_digit(*arg))
			arg++;
	}
	i = -1;
	head = *stack_a;
	len = get_list_len(*stack_a);
	while (++i < len)
	{
		get_index(*stack_a);
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head;
	return (*stack_a);
}

t_node	*parsing(t_node **stack, int argc, char *argv[])
{
	int		j;
	int		i;
	int		len;
	t_node	*head;

	i = -1;
	j = 0;
	if (!argv || !argv[1])
		return (NULL);
	while (++i < argc - 1)
	{
		if (check_invalid_arg(argv[++j]))
			return (NULL);
		if (!init_stack(stack, argv[j]))
			return (NULL);
		if (!stack)
			return (NULL);
	}
	i = -1;
	len = get_list_len(*stack);
	head = *stack;
	while (++i < len)
	{
		if (check_duplicate_arg(*stack))
			return (free_stack(stack, NULL));
		*stack = (*stack)->next;
	}
	*stack = head;
	return (*stack);
}

int	check_duplicate_arg(t_node *stack)
{
	int			current;
	t_node		*head;

	head = stack;
	current = stack->data;
	while (stack->next != head)
	{
		stack = stack->next;
		if (current == stack->data && stack->next != stack)
		{
			ft_printf("dup Error\n");
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	check_invalid_arg(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
		{
			if (str[i] == '-' && ft_isdigit(str[i + 1]))
				return (SUCCESS);
			ft_printf("invalid Error\n");
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	is_neg_digit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
	{
		return (1);
	}
	else
		return (0);
}
