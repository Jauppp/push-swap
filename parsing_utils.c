/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:03:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/09 17:18:00 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_node **stack)
{
	const size_t	len = get_list_len(*stack);
	size_t			i;
	t_node			*head;

	i = -1;
	head = *stack;
	while (++i < len)
	{
		get_index(*stack);
		*stack = (*stack)->next;
	}
	*stack = head;
}

t_node	*check_invalid_values(t_node *stack)
{
	size_t		i;
	size_t		len;
	t_node		*head;

	i = -1;
	len = get_list_len(stack);
	head = stack;
	while (++i < len)
	{
		if (check_duplicate_arg(stack))
			return (free_stack(&stack, NULL));
		if (stack->data > INT_MAX || stack->data < INT_MIN)
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (free_stack(&stack, NULL));
		}
		stack = stack->next;
	}
	stack = head;
	return (stack);
}

int	check_duplicate_arg(t_node *stack)
{
	long		current;
	t_node		*head;

	head = stack;
	current = stack->data;
	while (stack->next != head)
	{
		stack = stack->next;
		if (current == stack->data && stack->next != stack)
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	check_invalid_charset(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit_negative(str[i]) && !ft_isspace(str[i]))
		{
			// if (str[i] == '-' && ft_isdigit(str[i + 1]))
			// 	return (SUCCESS);
			write(STDERR_FILENO, "Error\n", 6);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

void	get_index(t_node *stack)
{
	size_t			i;
	size_t			len;
	t_node			*head;
	unsigned int	index;

	len = get_list_len(stack);
	i = -1;
	index = 0;

	head = stack;
	while (++i < len)
	{
		if (head->data > stack->data)
			index++;
		stack = stack->next;
	}
	stack->index = index;
	stack = head;
}