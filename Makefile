# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avuorio <avuorio@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/27 11:15:23 by avuorio       #+#    #+#                  #
#    Updated: 2021/05/27 11:30:46 by avuorio       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

SRCS_LIST		=	dll.c \
						utils.c 

SRCS			= $(addprefix srcs/, ${SRCS_LIST})

OBJS			= ${SRCS:%.c=%.o}

HEADER			= -I ./includes

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
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
