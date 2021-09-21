/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 12:32:46 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/21 09:17:04 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** swap function swaps the first two elements of stack with one another. variable
** 'stacks' defines which stack is modified by storing the data of the first 
** element in 'temp' variable, after which the data of second element becomes
** the first and the value in 'temp' is set as the data in the second element.
*/

void	swap(t_all *all, int stack, int op)
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
	if (op == SA)
		write(1, "sa\n", 3);
	else if (op == SB)
		write(1, "sb\n", 3);
	all->ops->counter++;
}

void	swap_ab(t_all *all)
{
	swap(all, A, -1);
	swap(all, B, -1);
	write(1, "ss\n", 3);
}
