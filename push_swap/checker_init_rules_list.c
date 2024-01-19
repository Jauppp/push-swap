/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_init_rules_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:35:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/19 14:47:39 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*get_input(t_list **rules)
{
	t_list	*new_node;

	new_node = ft_lstnew(get_next_line(STDIN_FILENO));
	if (!new_node)
		(ft_lstfree(rules));
	ft_lstadd_back(rules, new_node);
	return (*rules);
}

t_list	*init_rules(t_list **rules)
{
	t_list	*head;

	if (!get_input(rules))
		return (NULL);
	head = *rules;
	while ((*rules)->data)
	{
		if (!get_input(rules))
			return (ft_lstfree(rules));
		*rules = (*rules)->next;
	}
	*rules = head;
	return (*rules);
}

void	apply_current_rule(t_node **a, t_node **b, t_list **rules)
{
	if (ft_strncmp((char *)(*rules)->data, "sa\n", 4) == 0)
		checker_swap(a);
	else if (ft_strncmp((char *)(*rules)->data, "sb\n", 4) == 0)
		checker_swap(b);
	else if (ft_strncmp((char *)(*rules)->data, "ss\n", 4) == 0)
		checker_swap_ab(a, b);
	else if (ft_strncmp((char *)(*rules)->data, "ra\n", 4) == 0)
		checker_rotate(a);
	else if (ft_strncmp((char *)(*rules)->data, "rb\n", 4) == 0)
		checker_rotate(b);
	else if (ft_strncmp((char *)(*rules)->data, "rr\n", 4) == 0)
		checker_rotate_ab(a, b);
	else if (ft_strncmp((char *)(*rules)->data, "rra\n", 5) == 0)
		checker_reverse_rotate(a);
	else if (ft_strncmp((char *)(*rules)->data, "rrb\n", 5) == 0)
		checker_reverse_rotate(b);
	else if (ft_strncmp((char *)(*rules)->data, "rrr\n", 5) == 0)
		checker_reverse_rotate_ab(a, b);
	else if (ft_strncmp((char *)(*rules)->data, "pa\n", 4) == 0)
		checker_push(a, b);
	else if (ft_strncmp((char *)(*rules)->data, "pb\n", 4) == 0)
		checker_push(b, a);
}

void	apply_rules(t_node **a, t_node **b, t_list **rules)
{
	t_list	*head;

	head = *rules;
	while ((*rules)->next)
	{
		apply_current_rule(a, b, rules);
		*rules = (*rules)->next;
	}
	*rules = head;
}

int	list_not_sorted(t_node *stack)
{
	t_node	*head;

	if (!stack)
		return (ERROR);
	head = stack;
	while (stack->next != head)
	{
		if (stack->index > stack->next->index)
		{
			stack = head;
			return (ERROR);
		}
		stack = stack->next;
	}
	stack = head;
	return (SUCCESS);
}
