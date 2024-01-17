# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 11:29:44 by cdomet-d          #+#    #+#              #
#    Updated: 2024/01/17 18:12:09 by cdomet-d         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := checker
LIB := libft.a

CC := gcc
CFLAGS := -Werror -Wextra -Wall -g3 
CPPFLAGS = -MMD -MP
MAKEFLAGS += --no-print-directory
ARGS = "32 95 52 6 98 85 96 82 8 54 45 94 11 79 9 88 78 34 35 24 69 17 67 73 97 80 74 18 100 20 2 22 14 41 28 92 43 50 76 13 65 53 66 29 38 87 64 40 15 4 59 81 58 21 91 93 90 61 77 31 60 89 44 47 86 75 16 23 51 36 5 49 63 42 71 30 1 62 83 19 70 57 26 10 55 3 84 72 25 7 12 37 99 27 46 68 39 48 33 56"
BUILD_DIR := .dir_build
LIBFT_DIR := ../LIBFT

SRCS := main.c \
		both_stack_rules.c \
		chained_lists_utils.c \
		index_utils.c \
		parsing.c \
		parsing_utils.c \
		rules.c \
		init_rules_list.c \
		
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
	@./push_swap $(ARGS) | ./$(NAME) $(ARGS) > output.txt
	@echo -n "nb instructions : "
	@awk '/sa|sb|ss|ra|rb|rr|rra|rrb|rrr|pa|pb/' output.txt | wc -l
	@grep OK output.txt || grep KO output.txt

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