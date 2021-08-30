/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   define_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 14:11:55 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/30 10:37:46 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				ops->reverse_small++;
			else
				ops->reverse_big++;
			temp = temp->prev;
			print_address(temp, "temp add: ");
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

void	define_operations(t_data *all, int stack)
{
	move_small(all, all->ops, B);
	move_big(all, all->ops, B);
	print_data("big rotate: ", all->ops->rotate_big);
	print_data("big reverse: ", all->ops->reverse_big);
	print_data("small rotate: ", all->ops->rotate_small);
	print_data("small reverse: ", all->ops->reverse_small);
}
