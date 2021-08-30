/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   define_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 14:11:55 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/30 14:48:24 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** count functions count the number of moves to move min and max values in stack
** to either top or bottom of the stack.
*/

void	count_top(t_data *all, t_operations *ops, int stack, int opt)
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
				ops->rotate_small++;
			else
				ops->rotate_big++;
			temp = temp->next;
		}
	}
}

void	count_bottom(t_data *all, t_operations *ops, int stack, int opt)
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
				ops->reverse_small++;
			else
				ops->reverse_big++;
			temp = temp->prev;
		}
		if (opt == 1)
			ops->reverse_small++;
		else
			ops->reverse_big++;
	}
}

void	move_big(t_data *all, t_operations *ops, int stack)
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
		if (ops->rotate_big <= ops->reverse_big)
			ops->reverse_big = -1;
		else
			ops->rotate_big = -1;
	}
}

void	move_small(t_data *all, t_operations *ops, int stack)
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
		if (ops->rotate_small <= ops->reverse_small)
			ops->reverse_small = -1;
		else
			ops->reverse_small = -1;
	}
}

/*
** after defining the number of moves, define operations function compares
** the calculated values and defines the most efficient option to move to
** stack a, min or max value in stack b.
*/

void	define_operations(t_data *all, t_operations *ops, int stack)
{
	move_small(all, all->ops, stack);
	move_big(all, all->ops, stack);
	print_values(all);
	if ((ops->rotate_big >= ops->rotate_small
			&& ops->rotate_big >= ops->reverse_small) && ops->rotate_big != -1)
		ops->rotate_big = -1;
	else if ((ops->reverse_big >= ops->rotate_small
			&& ops->reverse_big >= ops->reverse_small) && ops->reverse_big != -1)
		ops->reverse_big = -1;
	else if ((ops->rotate_small >= ops->rotate_big
			&& ops->rotate_small >= ops->reverse_big) && ops->rotate_small != -1)
		ops->rotate_small = -1;
	else if ((ops->reverse_small >= ops->rotate_big
			&& ops->reverse_small >= ops->reverse_big) && ops->reverse_small != -1)
		ops->reverse_small = -1;
	if (ops->rotate_big != -1 || ops->reverse_big != -1)
		ops->big = 1;
	else if (ops->rotate_small != -1 || ops->reverse_small != -1)
		ops->small = 1;
	print_values(all);
}
