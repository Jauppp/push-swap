/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:28:35 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/17 17:52:26 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "sys/types.h" // ssize_t
# include "fcntl.h"
# include "stdio.h"
# include "../LIBFT/libft.h" // LIBFT header

# define ERROR 1
# define SUCCESS 0

typedef struct s_stack
{
	unsigned int	index;
	long			data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_node;

int		arg_is_empty(char *str);
int		arg_is_not_digit(char *str);
int		data_is_duplicate(t_node *stack);
int		data_is_invalid(t_node *stack);
int		rule_is_invalid(t_list *rules);
size_t	get_list_len(t_node *stack);
t_list	*get_input(t_list **rules);
t_list	*init_rules(t_list **rules);
t_node	*append_back(t_node **stack, t_node	*new_node);
t_node	*append_front(t_node **stack, t_node *new_node);
t_node	*free_stack(t_node **a, t_node **stack_b);
t_node	*init_stack(t_node **a, char *arg);
t_node	*parsing(t_node **stack, size_t argc, char *argv[]);
t_node	*stack_new(long data);
void	get_index(t_node *stack);
void	init_index(t_node **stack);
void	push(t_node **to, t_node **from, int c);
void	reverse_rotate_ab(t_node **a, t_node **stack_b);
void	reverse_rotate(t_node **stack, int c);
void	rotate_ab(t_node **a, t_node **stack_b);
void	rotate(t_node **stack, int c);
void	swap_ab(t_node **a, t_node **stack_b);
void	swap(t_node **stack, int c);
void	apply_current_rule(t_node **a, t_node **b, t_list **rules);
void	apply_rules(t_node **a, t_node **b, t_list **rules);
int		list_not_sorted(t_node *stack);
int 	input_is_invalid(t_node **a, t_node **b, t_list **rules);





#endif