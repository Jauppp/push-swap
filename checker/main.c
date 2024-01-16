/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:50:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/16 17:33:11 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_node		*a;
	t_node		*b;
	t_list		*instruct_list;
	// t_list		*head;

	if (!argv[1])
		return (ERROR);
	a = NULL;
	b = NULL;
	instruct_list = NULL;
	if (!parsing(&a, argc, argv))
		return (ERROR);
	get_instructions(&instruct_list);
	apply_instructions(&a, &b, instruct_list);
	free_stack(&a, &b);
}
