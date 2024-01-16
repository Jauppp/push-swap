/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instructions_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:14:42 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/16 17:48:50 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*init_instructions(t_list **instruct_list)
{
	t_list	*new_node;

	new_node = ft_lstnew(get_next_line(STDIN_FILENO));
	if (!new_node)
		(ft_lstfree(*instruct_list));
	ft_lstadd_back(instruct_list, new_node);
	return (*instruct_list);
}

t_list	*get_instructions(t_list **instruct_list)
{
	t_list	*head;

	init_instructions(instruct_list);
	head = *instruct_list;
	while ((*instruct_list)->content)
	{
		init_instructions(instruct_list);
		*instruct_list = (*instruct_list)->next;
	}
	*instruct_list = head;
	return (*instruct_list);
}

void	apply_instructions(t_node **a, t_node **b, t_list *instruct_list)
{
	while (instruct_list->next)
	{
		if (instruct_list->content == "sa")
			swap(a, 'a');
		if (instruct_list->content == "sb")
			swap(b, 'b');
		if (instruct_list->content == "ss")
			swap_ab(a, b);
		if (instruct_list->content == "ra")
			rotate(a, 'a');
		if (instruct_list->content == "rb")
			rotate(b, 'b');
		if (instruct_list->content == "rr")
			rotate_ab(a, b);
		if (instruct_list->content == "rra")
			reverse_rotate(a, 'a');
		if (instruct_list->content == "rrb")
			reverse_rotate(b, 'b');
		if (instruct_list->content == "rrr")
			reverse_rotate_ab(a, b);

	}
}
