/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_quarters.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 11:56:03 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/23 10:07:54 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push functions are used to push wanted quarters into stack B.
*/

void	push_1(t_all *all)
{
	if (all->b && all->b->data > all->quarter_1 / 2)
		rotate(all, B, RB);
	push(all, PB);
}

void	push_2(t_all *all)
{
	if (all->b && all->b->data > (all->median / 4) * 3)
		rotate(all, B, RB);
	push(all, PB);
}

void	push_3(t_all *all)
{
	if (all->b && all->b->data > (all->median / 4) * 5)
		rotate(all, B, RB);
	push(all, PB);
}

void	push_4(t_all *all)
{
	if (all->b && all->b->data > (all->median / 4) * 7)
		rotate(all, B, RB);
	push(all, PB);
}
