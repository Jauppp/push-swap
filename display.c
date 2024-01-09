/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:45:49 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/08 17:10:51 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack_a, t_node *stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	size_t	i;
	size_t	j;
	size_t	alen;
	size_t	blen;

	ft_printf("------------------------------------------------------------\n");
	temp_b = stack_b;
	temp_a = stack_a;
	if (!stack_a && !stack_b)
		return ;
	if (!stack_b && stack_a)
		print_single_stack(stack_a, 'a');
	else if (!stack_a && stack_b)
		print_single_stack(stack_b, 'b');
	else if (stack_a && stack_b)
	{
		i = 0;
		j = 0;
		alen = get_list_len(stack_a);
		blen = get_list_len(stack_b);
		while (i < alen || j < blen)
		{
			if (i < alen)
			{
				ft_printf("%d || %d\t\t", stack_a->data, stack_a->index);
				i++;
				stack_a = stack_a->next;
			}
			else
				ft_printf("\t\t");
			if (j < blen)
			{
				ft_printf("%d || %d\n", stack_b->data, stack_b->index);
				j++;
				stack_b = stack_b->next;
			}
			else
				ft_printf("\n");
		}
	}
	stack_a = temp_a;
	stack_b = temp_b;
	ft_printf("--------\t--------\n");
	ft_printf(" a || i");
	ft_printf(" \t b || i\n");
	ft_printf("------------------------------------------------------------\n");
}

void	print_single_stack(t_node *stack, int c)
{
	size_t	len;
	size_t	i;
	t_node	*head;

	i = 0;
	len = get_list_len(stack);
	head = stack;
	while (i < len)
	{
		if (c == 'b')
			ft_printf("\t\t");
		ft_printf("%d || %d\n", stack->data, stack->index);
		stack = stack->next;
		i++;
	}
	stack = head;
}
