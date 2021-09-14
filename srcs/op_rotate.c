/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 12:33:43 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/14 14:36:44 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		write(1, "ra\n", 4);
	else if (op == RB)
		write(1, "ra\n", 4);
	all->ops->counter++;
}

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
	write(1, "rr\n", 4);
}

void	reverse_rotate_ab(t_all *all)
{
	reverse_rotate(all, A, -1);
	reverse_rotate(all, B, -1);
	write(1, "rrr\n", 5);
}
