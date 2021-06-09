# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avuorio <avuorio@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/27 11:15:23 by avuorio       #+#    #+#                  #
#    Updated: 2021/06/09 09:20:03 by avuorio       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

SRCS_LIST		=	push_swap.c \
						checks.c utils1.c utils2.c \
						add.c operations.c solver.c \
						sort_five.c sort_hundred.c sort_more.c \
						find_values.c

SRCS			= $(addprefix srcs/, ${SRCS_LIST})

OBJS			= ${SRCS:%.c=%.o}

HEADER			= -I ./includes

CC				= gcc
#CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			$(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: 		all fclean clean re
