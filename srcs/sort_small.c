/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 12:52:45 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/16 14:00:52 by avuorio       ########   odam.nl         */
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
	find_values(all, A);
}

void	sort_small(t_data *all, int len)
{
	if (len == 2)
		two(all);
	else if (len == 3)
	 	three(all);
	else if (len == 4)
	 	four(all);
	// else if (len == 5)
	// 	five(all);
}
