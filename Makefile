# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 11:29:44 by cdomet-d          #+#    #+#              #
#    Updated: 2024/01/08 13:46:58 by cdomet-d         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
LIB := libft.a

CC := gcc
CFLAGS := -Werror -Wextra -Wall -g
CPPFLAGS = -MMD -MP
MAKEFLAGS += --no-print-directory

BUILD_DIR := .dir_build
LIBFT_DIR := LIBFT

SRCS := main.c \
		algorithm.c \
		parsing.c \
		rules.c \
		both_stack_rules.c \
		chained_lists_utils.c \
		display.c \
		algorithm_utils.c \
		
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:%.o=%.d)
RM := rm -rf

all: $(NAME)

$(LIBFT_DIR)/libft.a: FORCE
	@echo "Making LIBFT..."
	@$(MAKE) -C $(LIBFT_DIR) $(LIB)
	@echo

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	@echo
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft
	@echo "All done ! Thanks for waiting :)"
	
$(BUILD_DIR)/%.o:%.c push_swap.h LIBFT/libft.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< 

 -include $(DEPS)

clean: 
	@echo Cleaning...
	$(RM) $(BUILD_DIR) $(LIBFT_DIR)/$(BUILD_DIR)

fclean: clean
	$(RM) $(NAME) $(LIB)
	@echo Bye !
	@echo

re: fclean all

run: all
	@ echo "params : 2 3 1"
	@./$(NAME) "2 3 1"

invalid: all
	@echo "params : a e 125"
	@valgrind ./$(NAME) "a e 125"

dup: all
	@echo "params : 125 125"
	@valgrind ./$(NAME) "125 125"

seg: all
	@echo "params : 45 26 35 78 95 84 12"
	@valgrind ./$(NAME) "45 26 35 78 95 84 12"

leaks: all
	@echo "params : 45 26 35 78 95 84 12"
	@valgrind -s --leak-check=full ./$(NAME) "45 26 35 78 95 84 12"

debug: all
	@echo "Launching debugger"
	@echo "params : -2 -3 -1"
	@gdb -tui --args ./$(NAME) "-2 -3 -1"

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

.PHONY : clean fclean all re run seg leaks debug help kitty dup invalid
FORCE : 