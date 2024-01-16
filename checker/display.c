/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:45:49 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/16 16:17:43 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(t_node *a, t_node *b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	size_t	i;
	size_t	j;
	size_t	alen;
	size_t	blen;

	printf("------------------------------------------------------------\n");
	temp_b = b;
	temp_a = a;
	if (!a && !b)
		return ;
	if (!b && a)
		print_single_stack(a, 'a');
	else if (!a && b)
		print_single_stack(b, 'b');
	else if (a && b)
	{
		i = 0;
		j = 0;
		alen = get_list_len(a);
		blen = get_list_len(b);
		while (i < alen || j < blen)
		{
			if (i < alen)
			{
				printf("%ld || %d\t\t", a->data, a->index);
				i++;
				a = a->next;
			}
			else
				printf("\t\t");
			if (j < blen)
			{
				printf("%ld || %d\n", b->data, b->index);
				j++;
				b = b->next;
			}
			else
				printf("\n");
		}
	}
	a = temp_a;
	b = temp_b;
	printf("--------\t--------\n");
	printf(" a || i");
	printf(" \t b || i\n");
	printf("------------------------------------------------------------\n");
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
			printf("\t\t");
		printf("%ld || %d\n", stack->data, stack->index);
		stack = stack->next;
		i++;
	}
	stack = head;
}
