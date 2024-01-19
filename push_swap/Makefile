# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 11:29:44 by cdomet-d          #+#    #+#              #
#    Updated: 2024/01/19 16:20:05 by cdomet-d         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CHECKER := checker
LIB := libft.a

CC := gcc
CFLAGS := -Werror -Wextra -Wall -g3 
CPPFLAGS = -MMD -MP
MAKEFLAGS += --no-print-directory
ARGS := "500 24 966 25 3"

BUILD_DIR := .dir_build
LIBFT_DIR := ../LIBFT

SRCS := algorithm.c \
		algorithm_clarity.c \
		algorithm_utils.c \
		both_stack_rules.c \
		chained_lists_utils.c \
		index_utils.c \
		main.c \
		parsing.c \
		parsing_utils.c \
		rules.c \

SRCS_CHECKER := checker_init_rules_list.c \
				checker_instruction_parsing.c \
				checker_both_stack_rules.c \
				checker_main.c \
				checker_rules.c \
				checker_parsing.c \
				checker_parsing_utils.c \
				checker_chained_lists_utils.c \
				checker_index_utils.c \

OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
OBJS_CHECKER := $(SRCS_CHECKER:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:%.o=%.d)
DEPS_CHECKER := $(OBJS_CHECKER:%.o=%.d)
RM := rm -rf

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(LIBFT_DIR)/$(LIB) $(OBJS) 
	@echo
	@echo "$(PURPLE)|========== \t\t Making PUSH_SWAP \t\t ===========|$(BLACK)"
	@echo
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft
	@echo
	@echo "$(GREEN)|=========== \t\t PUSH_SWAP done ! \t\t ===========|$(BLACK)"
	@echo
$(CHECKER): $(LIBFT_DIR)/$(LIB) $(OBJS_CHECKER)
	@echo
	@echo "$(PURPLE)|========== \t\t Making CHECKER \t\t ===========|$(BLACK)"
	@echo
	$(CC) $(CFLAGS) $(OBJS_CHECKER) -o $(CHECKER) -L$(LIBFT_DIR) -lft
	@echo
	@echo "$(GREEN)|=========== \t\t CHECKER done ! \t\t ===========|$(BLACK)"
	@echo

$(BUILD_DIR)/%.o:%.c push_swap.h $(LIBFT_DIR)/libft.h checker.h Makefile
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIBFT_DIR)/$(LIB): FORCE
	@echo "$(FAINT)"
	$(MAKE) -C $(LIBFT_DIR) $(LIB) 
	@echo "$(RESET)"

 -include $(DEPS)
 -include $(DEPS_CHECKER)

clean: 
	@echo
	@echo "$(FAINT)$(PURPLE)|========== \t\t Cleaning... \t\t ===========|$(BLACK)"
	@echo
	$(RM) $(BUILD_DIR) $(LIBFT_DIR)/$(BUILD_DIR)

fclean: clean
	$(RM) $(NAME) $(CHECKER) $(LIBFT_DIR)/$(LIB)
	@echo
	@echo "$(FAINT)$(PURPLE)|========== \t\t Bye <3 \t\t ===========|$(BLACK)"
	@echo


re: fclean all

run: all
	@echo "$(UNDERLINE)params$(RESET) : $(ARGS)"
	@./$(NAME) $(ARGS) > output.txt
	@echo -n "$(UNDERLINE)nb instructions$(RESET) : "
	@awk '/sa|sb|ss|ra|rb|rr|rra|rrb|rrr|pa|pb/' output.txt | wc -l

display: run
	@awk '/------------------------------------------------------------/{found = 1} \
	found' output.txt | cat

help:
	@echo "make \t\t $(FAINT)makes push_swap.exe$(RESET)"
	@echo "make clean \t $(FAINT)deletes object files & dependencies$(RESET)"
	@echo "make fclean \t $(FAINT)deletes everything the makefile created$(RESET)"
	@echo "make kitty \t $(FAINT)prints a lil kitty on the terminal$(RESET)"
	@echo "make re \t $(FAINT)deletes all objects & dependencies and recompiles everything$(RESET)"
	@echo "make run \t $(FAINT)makes and runs push_swap with a preset of parameters$(RESET)"

kitty:
	@echo "   |\__/,|   ( \  "
	@echo " _.|o o  |_   ) ) "
	@echo "-(((---(((--------"

# Colors
BLACK=\033[30m
GREEN=\033[32m
PURPLE=\033[35m

# Text
RESET=\033[0m
FAINT=\033[2m
UNDERLINE=\033[4m

FORCE : 
.PHONY : clean fclean all re run help kitty display bonus