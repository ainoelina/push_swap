# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avuorio <avuorio@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/27 11:15:23 by avuorio       #+#    #+#                  #
#    Updated: 2021/06/10 13:26:55 by avuorio       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

SRCS_LIST		=	push_swap.c \
						checks.c utils1.c utils2.c \
						create_stack.c \
						add.c \
						push.c \
						tools.c

SRCS			= $(addprefix srcs/, $(SRCS_LIST))
DIR				= srcs/

OBJS_SRCS		= $(SRCS_LIST:.c=.o)
OBJS			= $(addprefix objs/, $(OBJS_SRCS))
OBJ_DIR			= objs/

HEADER			= -I ./includes

#CFLAGS 			= -Wall -Wextra -Werror !! REMEMBER TO ADD
RM				= rm -f

all:			$(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS)
	@echo "\033[38;5;205mpush_swap compiled ! :)\033[0m"

$(OBJ_DIR)%.o: $(DIR)%.c
	@mkdir -pp $(OBJ_DIR)
	@$(CC) -o $@ -c $< $(HEADER)
	@echo "\033[38;5;190mcompiling project ... \033[0m"

clean:
	@$(RM) $(OBJS)
	@echo "\033[38;5;2m~~~~ clean object files ! ~~~~~~\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@rmdir objs
	@echo "\033[38;5;10m~~~~ clean executable ! ~~~~~~~~\033[0m"

re: fclean all

.PHONY: 		all fclean clean re
