/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 12:33:43 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/21 09:16:55 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rotate function shifts all elements in a stack up by 1. the top element
** becomes the last. variable 'stack' defines which stack is modified, simply
** by moving the ->next node to the top of the stack/linked list.
*/

void	rotate(t_all *all, int stack, int op)
{
	if (stack == A)
	{
		if (all->a)
			all->a = all->a->next;
	}
	else if (stack == B)
	{
		if (all->b)
			all->b = all->b->next;
	}
	if (op == RA)
		write(1, "ra\n", 3);
	else if (op == RB)
		write(1, "ra\n", 3);
	all->ops->counter++;
}

/*
** reverse_rotate works similarly to rotate function, only the elements
** are moved down by one, and the last element becomes the first.
*/

void	reverse_rotate(t_all *all, int stack, int op)
{
	if (stack == A)
	{
		if (all->a)
			all->a = all->a->prev;
	}
	else if (stack == B)
	{
		if (all->b)
			all->b = all->b->prev;
	}
	if (op == RRA)
		write(1, "rra\n", 4);
	else if (op == RRB)
		write(1, "rra\n", 4);
	all->ops->counter++;
}

void	rotate_ab(t_all *all)
{
	rotate(all, A, -1);
	rotate(all, B, -1);
	write(1, "rr\n", 3);
}

void	reverse_rotate_ab(t_all *all)
{
	reverse_rotate(all, A, -1);
	reverse_rotate(all, B, -1);
	write(1, "rrr\n", 4);
}
