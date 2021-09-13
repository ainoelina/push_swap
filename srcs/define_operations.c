/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   define_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 14:11:55 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/13 10:58:44 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** count functions count the number of moves to move min and max values in stack
** to either top or bottom of the stack.
*/

void	count_top(t_all *all, t_operations *ops, int stack, int opt)
{
	t_list	*temp;
	int		nb;

	if (stack == A)
		temp = all->a;
	else
		temp = all->b;
	if (temp)
	{
		if (opt == 1)
			nb = all->min;
		else
			nb = all->max;
		while (temp->data != nb)
		{
			if (opt == 1)
				ops->r_small++;
			else
				ops->r_big++;
			temp = temp->next;
		}
	}
}

void	count_bottom(t_all *all, t_operations *ops, int stack, int opt)
{
	t_list	*temp;
	int		nb;

	if (stack == A)
	{
		last_node(all, A);
		temp = all->last_node;
	}
	else
	{
		last_node(all, B);
		temp = all->last_node;
	}
	if (temp)
	{
		if (opt == 1)
			nb = all->min;
		else
			nb = all->max;
		while (temp->data != nb)
		{
			if (opt == 1)
				ops->rr_small++;
			else
				ops->rr_big++;
			temp = temp->prev;
		}
		if (opt == 1)
			ops->rr_small++;
		else
			ops->rr_big++;
	}
}

void	move_big(t_all *all, t_operations *ops, int stack)
{
	t_list	*temp;
	int		opt;

	if (stack == A)
		temp = all->a;
	else
		temp = all->b;
	opt = 2;
	if (temp)
	{
		count_top(all, ops, stack, opt);
		count_bottom(all, ops, stack, opt);
		if (ops->r_big <= ops->rr_big)
			ops->rr_big = -1;
		else
			ops->r_big = -1;
	}
}

void	move_small(t_all *all, t_operations *ops, int stack)
{
	t_list	*temp;
	int		opt;

	if (stack == A)
		temp = all->a;
	else
		temp = all->b;
	opt = 1;
	if (temp)
	{
		count_top(all, ops, stack, opt);
		count_bottom(all, ops, stack, opt);
		if (ops->r_small <= ops->rr_small)
			ops->rr_small = -1;
		else
			ops->rr_small = -1;
	}
}

/*
** after defining the number of moves, define operations function compares
** the calculated values and defines the most efficient option to move to
** stack a, min or max value in stack b.
*/

void	define_operations(t_all *all, t_operations *ops, int stack)
{
	move_small(all, all->ops, stack);
	move_big(all, all->ops, stack);
	print_values(all);
	if ((ops->r_big >= ops->r_small
			&& ops->r_big >= ops->rr_small) && ops->r_big != -1)
		ops->r_big = -1;
	else if ((ops->rr_big >= ops->r_small
			&& ops->rr_big >= ops->rr_small)
		&& ops->rr_big != -1)
		ops->rr_big = -1;
	else if ((ops->r_small >= ops->r_big
			&& ops->r_small >= ops->rr_big)
		&& ops->r_small != -1)
		ops->r_small = -1;
	else if ((ops->rr_small >= ops->r_big
			&& ops->rr_small >= ops->rr_big)
		&& ops->rr_small != -1)
		ops->rr_small = -1;
	if (ops->r_big != -1 || ops->rr_big != -1)
		ops->big = 1;
	else if (ops->r_small != -1 || ops->rr_small != -1)
		ops->small = 1;
	print_values(all);
}
