/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:28:35 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/17 16:55:34 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "sys/types.h" // ssize_t
# include "../LIBFT/libft.h" // LIBFT header

# define ERROR 1
# define SUCCESS 0
# define S_LIST  150
# define M_LIST  300
# define S_CHUNK 11.5
# define M_CHUNK 14.5
# define L_CHUNK 17.5
# define NO_INTERMEDIATE_SORT 3
# define INTERMEDIATE_SORT 19


typedef struct s_stack
{
	unsigned int	index;
	long			data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_node;

int				arg_is_empty(char *str);
int				arg_is_not_digit(char *str);
int				bhead_can_be_pushed(t_node **a, \
				t_node **b, size_t max_a, size_t max_b);
int				both_stacks_need_rotate(t_node **a, t_node **b);
int				data_is_duplicate(t_node *stack);
int				data_is_invalid(t_node *stack);
int				list_not_sorted(t_node *stack);
int				next_in_first_half(t_node *stack, unsigned int goal);
size_t			get_list_len(t_node *stack);
t_node			*append_back(t_node **stack, t_node	*new_node);
t_node			*append_front(t_node **stack, t_node *new_node);
t_node			*free_stack(t_node **a, t_node **stack_b);
t_node			*init_stack(t_node **a, char *arg);
t_node			*parsing(t_node **stack, size_t argc, char *argv[]);
t_node			*stack_new(long data);
unsigned int	find_max(t_node *stack);
unsigned int	find_min(t_node *stack);
void			get_chunk_and_sort(t_node **a, t_node **stack_b);
void			get_index(t_node *stack);
void			init_index(t_node **stack);
void			pb_and_increment(t_node **a, \
				t_node **b, size_t *len, size_t *goal);
void			print_single_stack(t_node *stack, int c);
void			print_stack(t_node *a, t_node *stack_b);
void			push_bhead(t_node **a, t_node **b, size_t *max_b);
void			push(t_node **to, t_node **from, int c);
void			reverse_rotate_ab(t_node **a, t_node **stack_b);
void			reverse_rotate(t_node **stack, int c);
void			rotate_ab(t_node **a, t_node **stack_b);
void			rotate(t_node **stack, int c);
void			swap_ab(t_node **a, t_node **stack_b);
void			swap(t_node **stack, int c);

#endif