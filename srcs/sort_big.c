/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 12:12:27 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/22 12:01:27 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_quarters(t_all *all, t_list *stack, t_list *end, int part)
{
	int		stop;

	stop = 0;
	find_values(all, A);
	while (stop != 1)
	{
		if (stack == end)
			stop = 1;
		if (part == 1 && stack->data <= all->quarter_1)
			push_1(all);
		else if (part == 2 && stack->data > all->quarter_1
			&& stack->data <= all->median)
			push_2(all);
		else if (part == 3 && stack->data > all->median
			&& stack->data <= all->quarter_3)
			push_3(all);
		else if (part == 4 && stack->data > all->quarter_3)
			push_4(all);
		else if (part == 4 && stack->data == all->min)
			break ;
		else
			rotate(all, A, RA);
		stack = all->a;
	}
	reset(all, all->ops);
}

void	sort_big(t_all *all, t_operations *ops)
{
	int	part;

	part = 1;
	median(all, A);
	while (all->a)
	{
		push_quarters(all, all->a, all->a->prev, part);
		while (all->b)
			do_sorting(all, all->ops);
		while (ops->tracker)
		{
			ops->tracker--;
			if (ops->tracker == 0)
				break ;
			rotate(all, A, RA);
		}
		part++;
		if (part == 5)
			break ;
	}
}
