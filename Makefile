# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avuorio <avuorio@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/27 11:15:23 by avuorio       #+#    #+#                  #
#    Updated: 2021/09/22 12:22:57 by avuorio       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

SRCS_LIST		=	push_swap.c \
						checks.c utils.c \
						initialise.c create_stack.c \
						sort.c sort_small.c sort_medium.c sort_big.c \
						find_values.c median.c \
						define_operations.c sort_rotate.c \
						handle_quarters.c \
						modify_stack.c free.c \
						op_push.c op_swap.c op_rotate.c

SRCS			= $(addprefix srcs/, $(SRCS_LIST))
DIR				= srcs/

OBJS_SRCS		= $(SRCS_LIST:.c=.o)
OBJS			= $(addprefix objs/, $(OBJS_SRCS))
OBJ_DIR			= objs/

HEADER			= -I ./includes

CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			$(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS)
	@echo "\\n\033[35;1m  PUSH_SWAP COMPILED ! :)\033[0m \\n"

$(OBJ_DIR)%.o: $(DIR)%.c
	@echo "\\033[2;1m  making of: push_swap...\033[0m"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)

clean:
	@$(RM) $(OBJS)
	@echo "\\n\033[35;1m  object files cleaned ! :)\033[0m \\n"

fclean: clean
	@$(RM) $(NAME)
	@rmdir objs
	@echo "\\033[35;1m  executable cleaned ! :)\033[0m \\n"

re: fclean all

.PHONY: 		all fclean clean re
