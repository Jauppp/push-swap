/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:50:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/19 13:55:07 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_node		*a;
	t_node		*b;
	t_list		*rules;

	if (!argv[1])
		return (STDERR_FILENO);
	a = NULL;
	b = NULL;
	rules = NULL;
	if (!parse_and_init_stack(&a, argc, argv))
		return (STDERR_FILENO);
	if (!init_rules(&rules))
	{
		free_stack(&a, &b);
		return (STDERR_FILENO);
	}
	if (input_is_invalid(&a, &b, &rules))
		return (STDERR_FILENO);
	apply_rules(&a, &b, &rules);
	if (list_not_sorted(a) || b)
		ft_printf("KO\n");
	else if (!list_not_sorted(a) && !b)
		ft_printf("OK\n");
	ft_lstfree(&rules);
	free_stack(&a, &b);
}
