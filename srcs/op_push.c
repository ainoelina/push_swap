/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 13:18:29 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/14 14:37:19 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_all *all, int op)
{
	int	save;

	if (op == PA)
	{
		if (all->b)
		{
			save = all->b->data;
			delete_top(all, B);
			insert_top(all, A, save);
			write(1, "pa\n", 3);
		}
	}
	else if (op == PB)
	{
		if (all->a)
		{
			save = all->a->data;
			delete_top(all, A);
			insert_top(all, B, save);
			write(1, "pb\n", 3);
		}
	}
	all->ops->counter++;
}
