/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:33:12 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/19 13:54:05 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	input_is_invalid(t_node **a, t_node **b, t_list **rules)
{
	t_list	*head;

	head = *rules;
	while ((*rules)->next)
	{
		if (rule_is_invalid(*rules))
		{
			*rules = head;
			ft_lstfree(rules);
			free_stack(a, b);
			write(2, "Error\n", 6);
			return (STDERR_FILENO);
		}
		*rules = (*rules)->next;
	}
	*rules = head;
	return (SUCCESS);
}

int	rule_is_invalid(t_list *rules)
{
	if (ft_strncmp((char *)rules->data, "sa\n", 4) == 0)
		return (SUCCESS);
	else if (ft_strncmp((char *)rules->data, "sb\n", 4) == 0)
		return (SUCCESS);
	else if (ft_strncmp((char *)rules->data, "ss\n", 4) == 0)
		return (SUCCESS);
	else if (ft_strncmp((char *)rules->data, "ra\n", 4) == 0)
		return (SUCCESS);
	else if (ft_strncmp((char *)rules->data, "rb\n", 4) == 0)
		return (SUCCESS);
	else if (ft_strncmp((char *)rules->data, "rr\n", 4) == 0)
		return (SUCCESS);
	else if (ft_strncmp((char *)rules->data, "rra\n", 5) == 0)
		return (SUCCESS);
	else if (ft_strncmp((char *)rules->data, "rrb\n", 5) == 0)
		return (SUCCESS);
	else if (ft_strncmp((char *)rules->data, "rrr\n", 5) == 0)
		return (SUCCESS);
	else if (ft_strncmp((char *)rules->data, "pa\n", 4) == 0)
		return (SUCCESS);
	else if (ft_strncmp((char *)rules->data, "pb\n", 4) == 0)
		return (SUCCESS);
	else
		return (ERROR);
}
