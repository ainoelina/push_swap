/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 12:32:46 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/13 10:53:44 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_all *all, int stack)
{
	int	temp;

	if (stack == A)
	{
		if (all->a && all->a->next != all->a)
		{
			temp = all->a->data;
			all->a->data = all->a->next->data;
			all->a->next->data = temp;
		}
	}
	if (stack == B)
	{
		if (all->b && all->b->next != all->b)
		{
			temp = all->b->data;
			all->b->data = all->b->next->data;
			all->b->next->data = temp;
		}
	}
}

void	swap_ab(t_all *all)
{
	swap(all, A);
	swap(all, B);
}
