/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:50:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/15 14:40:51 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	if (!argv[1])
		return (ERROR);
	a = NULL;
	b = NULL;
	if (!parsing(&a, argc, argv))
		return (ERROR);
	if (list_not_sorted(a))
		get_chunk_and_sort(&a, &b);
	else
	{
		free_stack(&a, NULL);
		return (ERROR);
	}
	free_stack(&a, &b);
}
