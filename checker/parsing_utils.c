/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:03:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/16 16:17:50 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	data_is_invalid(t_node *stack)
{
	size_t		i;
	size_t		len;
	t_node		*head;

	i = 0;
	len = get_list_len(stack);
	head = stack;
	while (i < len)
	{
		if (data_is_duplicate(stack))
			return (ERROR);
		if (stack->data > INT_MAX || stack->data < INT_MIN)
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (ERROR);
		}
		stack = stack->next;
		i++;
	}
	stack = head;
	return (SUCCESS);
}

int	data_is_duplicate(t_node *stack)
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

int	arg_is_not_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit_negative(str[i]) && !ft_isspace(str[i]))
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (ERROR);
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (i != 0 && str[i] == '-' && !ft_isspace(str[i - 1]))
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	arg_is_empty(char *str)
{
	size_t	i;

	i = 0;
	if (!str || !str[i])
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (ERROR);
	}
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (SUCCESS);
		i++;
	}
	write(STDERR_FILENO, "Error\n", 6);
	return (ERROR);
}
