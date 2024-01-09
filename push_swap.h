/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:28:35 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/09 18:31:07 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "sys/types.h" // ssize_t
# include "LIBFT/libft.h" // LIBFT header
#include "stdio.h" // PRINTF TO REMOVE

# define ERROR 1
# define SUCCESS 0
# define SMALL_STACK 4
# define EQUATION 

typedef struct s_stack
{
	unsigned int	index;
	long			data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_node;

int				check_duplicate_arg(t_node *stack);
int				check_invalid_charset(char *str);
int				is_neg_digit(int c);
size_t			get_list_len(t_node *stack);
t_node			*append_back(t_node **stack, t_node	*new_node);
t_node			*append_front(t_node **stack, t_node *new_node);
t_node			*check_invalid_values(t_node *stack);
t_node			*free_stack(t_node **stack_a, t_node **stack_b);
t_node			*init_stack(t_node **stack_a, char *arg);
t_node			*parsing(t_node **stack, size_t argc, char *argv[]);
t_node			*stack_new(long data);
unsigned int	find_max(t_node *stack);
unsigned int	find_min(t_node *stack);
void			get_index(t_node *stack);
void			init_index(t_node **stack);
void			print_single_stack(t_node *stack, int c);
void			print_stack(t_node *stack_a, t_node *stack_b);
void			push(t_node **to, t_node **from, int c);
void			reverse_rotate_ab(t_node **stack_a, t_node **stack_b);
void			reverse_rotate(t_node **stack, int c);
void			rotate_ab(t_node **stack_a, t_node **stack_b);
void			rotate(t_node **stack, int c);
void			sort_by_index(t_node **stack_a, t_node **stack_b);
void			sort_small_stack(t_node **stack_a);
void			sort(t_node **stack_a, t_node **stack_b);
void			swap_ab(t_node **stack_a, t_node **stack_b);
void			swap(t_node **stack, int c);

#endif