/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:28:35 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/19 14:45:52 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		data_is_duplicate(t_node *stack);
int		input_is_invalid(t_node **a, t_node **b, t_list **rules);
int		rule_is_invalid(t_list *rules);
t_list	*get_input(t_list **rules);
t_list	*init_rules(t_list **rules);
t_node	*free_stack(t_node **a, t_node **stack_b);
t_node	*init_stack(t_node **a, char *arg);
t_node	*parse_and_init_stack(t_node **stack, size_t argc, char *argv[]);
void	apply_current_rule(t_node **a, t_node **b, t_list **rules);
void	apply_rules(t_node **a, t_node **b, t_list **rules);
void	checker_push(t_node **to, t_node **from);
void	checker_reverse_rotate_ab(t_node **a, t_node **stack_b);
void	checker_reverse_rotate(t_node **stack);
void	checker_rotate_ab(t_node **a, t_node **stack_b);
void	checker_rotate(t_node **stack);
void	checker_swap_ab(t_node **a, t_node **stack_b);
void	checker_swap(t_node **stack);

#endif