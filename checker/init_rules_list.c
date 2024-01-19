/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:14:42 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/17 15:33:57 by cdomet-d         ###   ########lyon.fr   */
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

void	apply_current_rule(t_node **a, t_node **b, t_list **rules)
{
    if (ft_strncmp((char *)(*rules)->data, "sa\n", 4) == 0)
        swap(a, 'a');
    else if (ft_strncmp((char *)(*rules)->data, "sb\n", 4) == 0)
        swap(b, 'b');
    else if (ft_strncmp((char *)(*rules)->data, "ss\n", 4) == 0)
        swap_ab(a, b);
    else if (ft_strncmp((char *)(*rules)->data, "ra\n", 4) == 0)
        rotate(a, 'a');
    else if (ft_strncmp((char *)(*rules)->data, "rb\n", 4) == 0)
        rotate(b, 'b');
    else if (ft_strncmp((char *)(*rules)->data, "rr\n", 4) == 0)
        rotate_ab(a, b);
    else if (ft_strncmp((char *)(*rules)->data, "rra\n", 5) == 0)
        reverse_rotate(a, 'a');
    else if (ft_strncmp((char *)(*rules)->data, "rrb\n", 5) == 0)
        reverse_rotate(b, 'b');
    else if (ft_strncmp((char *)(*rules)->data, "rrr\n", 5) == 0)
        reverse_rotate_ab(a, b);
    else if (ft_strncmp((char *)(*rules)->data, "pa\n", 4) == 0)
        push(a, b, 'a');
    else if (ft_strncmp((char *)(*rules)->data, "pb\n", 4) == 0)
        push(b, a, 'b');
}

void apply_rules(t_node **a, t_node **b, t_list **rules)
{
    t_list *head;

    head = *rules;
    while ((*rules)->next)
    {
        apply_current_rule(a, b, rules);
        *rules = (*rules)->next;
    }
    *rules = head;
}

int input_is_invalid(t_node **a, t_node **b, t_list **rules)
{
    t_list *head;

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

int	list_not_sorted(t_node *stack)
{
	t_node			*head;

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