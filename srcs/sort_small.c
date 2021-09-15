/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 12:52:45 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/15 10:45:05 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** sort_small.c handles the sorting of five numbers or less, optimising the
** number of operations used.
*/

void	two(t_all *all)
{
	if (all->a->data > all->a->next->data)
		swap(all, A, SA);
}

void	three(t_all *all)
{
	int	top;
	int	middle;
	int	bottom;

	top = all->a->data;
	middle = all->a->next->data;
	bottom = all->a->next->next->data;
	if (top > middle && middle < bottom && bottom > top)
		swap(all, A, SA);
	if (top > middle && middle < bottom && bottom < top)
		rotate(all, A, RA);
	if (top < middle && middle > bottom && bottom < top)
		reverse_rotate(all, A, RRA);
	if (top > middle && middle > bottom && bottom < top)
	{
		swap(all, A, SA);
		reverse_rotate(all, A, RRA);
	}
	if (top < middle && middle > bottom && bottom > top)
	{
		swap(all, A, SA);
		rotate(all, A, RA);
	}
}

void	four(t_all *all)
{
	t_list	*temp;

	find_values(all, A);
	temp = all->a;
	while (temp->data != all->min)
	{
		rotate(all, A, RA);
		temp = temp->next;
	}
	push(all, PB);
	three(all);
	push(all, PA);
}

void	five(t_all *all)
{
	int	steps;

	steps = 0;
	median(all, A);
	while (steps <= 5)
	{
		if (all->a->data < all->median)
		{
			push(all, PB);
			steps++;
		}
		else
		{
			rotate(all, A, RA);
			steps++;
		}
	}
	three(all);
	if (all->b->data < all->b->next->data)
		swap(all, B, SB);
	push(all, PA);
	push(all, PA);
}

void	sort_small(t_all *all, int len)
{
	if (len == 2)
		two(all);
	else if (len == 3)
		three(all);
	else if (len == 4)
		four(all);
	else if (len == 5)
		five(all);
}
