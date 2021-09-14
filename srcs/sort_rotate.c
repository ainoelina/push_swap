/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_rotate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/30 12:56:31 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/14 14:35:45 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_small(t_all *all, t_operations *ops)
{
	if (ops->r_small >= 0)
	{
		while (ops->r_small)
		{
			rotate(all, B, RB);
			ops->r_small--;
		}
	}
	else if (ops->rr_small >= 0)
	{
		while (ops->rr_small)
		{
			reverse_rotate(all, B, RRB);
			ops->rr_small--;
		}
	}
}

void	check_big(t_all *all, t_operations *ops)
{
	if (ops->r_big >= 0)
	{
		while (ops->r_big)
		{
			rotate(all, B, RB);
			ops->r_big--;
		}
	}
	else if (ops->rr_big >= 0)
	{
		while (ops->rr_big)
		{
			reverse_rotate(all, B, RRB);
			ops->rr_big--;
		}
	}
}
