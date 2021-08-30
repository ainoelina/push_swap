/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_medium.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/23 13:10:50 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/30 14:16:38 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push_chunk function loops trough the stack and pushes all values
** smaller/bigger or equal to median to the stack b, depending on 
** the chunk number.
*/

void	push_chunk(t_data *all, int chunk)
{
	t_list	*temp;

	temp = all->a;
	last_node(all, A);
	find_values(all, A);
	while (1)
	{
		if (temp == all->last_node)
			break ;
		if (chunk == 1 && temp->data <= all->median)
			push(&all->b, &all->a, all);
		else
			rotate(all, A);
		temp = all->a;
	}
}

void	do_rotate(t_data *all, t_operations *ops)
{
	check_big(all, ops);
	check_small(all, ops);
	push(&all->a, &all->b, all);
	if (ops->small)
		rotate(all, A);
	if (ops->big || all->b == NULL)
		ops->tracker++;
	reset(ops);
}

void	push_stack(t_data *all, t_list *stack)
{
	last_node(all, B);
	while (1)
	{
		while (stack->data != all->min && stack->data != all->max)
			stack = stack->next;
		if (stack->data == all->min || stack->data == all->max)
		{
			do_rotate(all, all->ops);
			break ;
		}
		else
			stack = stack->next;
		if (stack == all->last_node)
			break ;
		stack = all->b;
	}
}

void	sort_medium(t_data *all)
{
	int	chunk;

	chunk = 1;
	median(all, A);
	while (all->a)
	{
		push_chunk(all, chunk);
		while (all->b)
		{
			find_values(all, B);
			define_operations(all, B);
			if (all->b && (all->ops->rotate_big >= 0
					|| all->ops->reverse_big >= 0 || all->ops->rotate_small >= 0
					|| all->ops->reverse_small >= 0))
			{
				push_stack(all, all->b);
			}
		}
		while (all->ops->tracker)
		{
			rotate(all, A);
			all->ops->tracker--;
		}
		chunk++;
		if (chunk == 3)
			break ;
	}
}
