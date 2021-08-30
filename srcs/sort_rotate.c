/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_rotate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/30 12:56:31 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/30 13:05:50 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_small(t_data *all, t_operations *ops)
{
	if (ops->rotate_small >= 0)
	{
		while (ops->rotate_small)
		{
			rotate(all, B);
			ops->rotate_small--;
		}
	}
	else if (ops->reverse_small >= 0)
	{
		while (ops->reverse_small)
		{
			reverse_rotate(&all->b);
			ops->reverse_small--;
		}
	}
}

void	check_big(t_data *all, t_operations *ops)
{
	if (ops->rotate_big >= 0)
	{
		while (ops->rotate_big)
		{
			rotate(all, B);
			ops->rotate_big--;
		}
	}
	else if (ops->reverse_big >= 0)
	{
		while (ops->reverse_big)
		{
			reverse_rotate(&all->b);
			ops->reverse_big--;
		}
	}
}