# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 11:29:44 by cdomet-d          #+#    #+#              #
#    Updated: 2024/01/17 10:06:10 by cdomet-d         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := checker
LIB := libft.a

CC := gcc
CFLAGS := -Werror -Wextra -Wall -g3 
CPPFLAGS = -MMD -MP
MAKEFLAGS += --no-print-directory
ARGS = "50 55 45 35 30 25 20 15 5 10"
BUILD_DIR := .dir_build
LIBFT_DIR := ../LIBFT

SRCS := main.c \
		algorithm_utils.c \
		algorithm_clarity.c \
		algorithm.c \
		both_stack_rules.c \
		chained_lists_utils.c \
		index_utils.c \
		parsing_utils.c \
		parsing.c \
		rules.c \
		init_instructions_list.c \
		
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:%.o=%.d)
RM := rm -rf

all: $(NAME)

$(LIBFT_DIR)/$(LIB): FORCE
	@echo "Making LIBFT..."
	@$(MAKE) -C $(LIBFT_DIR) $(LIB)
	@echo

$(NAME): $(LIBFT_DIR)/$(LIB) $(OBJS)
	@echo
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft
	@echo "All done ! Thanks for waiting :)"
	
$(BUILD_DIR)/%.o:%.c checker.h $(LIBFT_DIR)/libft.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< 

 -include $(DEPS)

clean: 
	@echo Cleaning...
	$(RM) $(BUILD_DIR) $(LIBFT_DIR)/$(BUILD_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT_DIR)/$(LIB)
	@echo Bye !
	@echo

re: fclean all

run: all
	@echo "params : $(ARGS)"
	@./$(NAME) $(ARGS) > output.txt
	@echo -n "nb instructions : "
	@awk '/sa|sb|ss|ra|rb|rr|rra|rrb|rrr|pa|pb/' output.txt | wc -l

display: run
	@awk '/------------------------------------------------------------/{found = 1} \
	found' output.txt | cat

seg: all
	@echo "params : $(ARGS)"
	@valgrind ./$(NAME) $(ARGS) > output.txt

leaks: all
	@echo "params : $(ARGS)"
	@valgrind -s --leak-check=full ./$(NAME) $(ARGS)

debug: all
	@echo "Launching debugger"
	@echo "params : $(ARGS)"
	@gdb -tui --args ./$(NAME) $(ARGS)

help:
	@echo "Make \t\t makes push_swap.exe"
	@echo "Make clean \t deletes object files & dependencies"
	@echo "Make debug \t launches GDB with a preset of parameters"
	@echo "Make fclean \t deletes everything the makefile created"
	@echo "Make kitty \t prints a lil kitty on the terminal"
	@echo "Make leaks \t runs push_swap with valgrind -s --leak-check=full"
	@echo "Make re \t deletes all objects & dependencies and recompiles everything"
	@echo "Make run \t makes and runs push_swap with a preset of parameters"
	@echo "Make seg \t runs push_swap with valgrind"


kitty:
	@echo "   |\__/,|   ( \  "
	@echo " _.|o o  |_   ) ) "
	@echo "-(((---(((--------"

.PHONY : clean fclean all re run seg leaks debug help kitty dup invalid display
FORCE : 