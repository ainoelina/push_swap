/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 12:52:45 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/29 12:35:26 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	bottom = all->a->next->next->data;
	if (top > middle && middle < bottom && bottom > top)
		swap(all, A);
	if (top > middle && middle < bottom && bottom < top)
		rotate(all, A);
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
	while (temp->data != all->small)
	{
		rotate(all, A);
		temp = temp->next;
	}
	push(&all->b, &all->a, all);
	three(all);
	push(&all->a, &all->b, all);
}

/*
** ongelma viiden lajittelun kanssa, infinite loop
*/

void	five(t_data *all)
{
	t_list	*temp;
	t_list	*end;

	end = all->a->prev;
	printf("end is %p\n", end);
	median(all, A);
	temp = all->a;
	while (temp)
	{
//		printf("is the problem here\n");
		if (temp == NULL)
			break ;
		if (all->a->data < all->median)
			push(&all->b, &all->a, all);
		else
			rotate(all, A);
	}
	three(all);
	temp = all->b->next;
	if (all->b->data < temp->data)
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
