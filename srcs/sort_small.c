/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 12:52:45 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/25 15:53:21 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** sort_small.c handles the sorting of five numbers or less.
*/

void	two(t_data *all)
{
	if (all->a->data > all->a->next->data)
		swap(all, A);
}

void	three(t_data *all)
{
	int	top;
	int	middle;
	int	bottom;

	top = all->a->data;
	middle = all->a->next->data;
	printf("whattt\n");
	bottom = all->a->next->next->data;
	if (top > middle && middle < bottom && bottom > top)
		swap(all, A);
	if (top > middle && middle < bottom && bottom < top)
		rotate_a(&all->a);
	if (top < middle && middle > bottom && bottom < top)
		reverse_rotate(&all->a);
	if (top > middle && middle > bottom && bottom < top)
	{
		swap(all, A),
		reverse_rotate(&all->a);
	}
	if (top < middle && middle > bottom && bottom > top)
	{
		swap(all, A);
		rotate(all, A);
	}
}

void	four(t_data *all)
{
	t_list	*temp;

	find_values(all, A);
	temp = all->a;
	while (temp->data != all->min)
	{
		rotate(all, A);
		temp = temp->next;
	}
	push(&all->b, &all->a, all);
	three(all);
	push(&all->a, &all->b, all);
}

void	five(t_data *all)
{
	int	steps;

	steps = 0;
	median(all, A);
	while (steps <= 5)
	{
		if (all->a->data < all->median)
		{
			push(&all->b, &all->a, all);
			steps++;
		}
		else
		{
			rotate(all, A);
			steps++;
		}
	}
	three(all);
	if (all->b->data < all->b->next->data)
		swap(all, B);
	push(&all->a, &all->b, all);
	push(&all->a, &all->b, all);
}

void	sort_small(t_data *all, int len)
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
