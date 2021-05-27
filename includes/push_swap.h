/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 12:25:22 by avuorio       #+#    #+#                 */
/*   Updated: 2021/05/27 11:09:54 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	unsigned int	size;
}				t_stack;

/*
** ~~~~~~~~ OPERATIONS ~~~~~
*/

void	swap(t_node **head);

/*
** ~~~~~~~~ UTILS ~~~~~
*/
void	*malloc_memory(size_t size)

#endif