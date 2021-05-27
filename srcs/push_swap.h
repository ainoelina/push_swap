/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:44:15 by avuorio       #+#    #+#                 */
/*   Updated: 2021/05/27 14:58:04 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef	struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct s_stack
{
	t_list	*head;
	t_list	*tail;
	int		top;
	int		argc;
}				t_stack;

void	*malloc_memory(size_t size);

int		my_atoi(char *str);

void	add_to_stack(t_stack *a, t_list *node, char *str);

#endif