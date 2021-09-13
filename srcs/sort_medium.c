/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_medium.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/23 13:10:50 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/13 08:54:27 by avuorio       ########   odam.nl         */
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
	int	flag = 0;

	temp = all->a;
	last_node(all, A);
	find_values(all, A);
	while (1)
	{
		if (temp == all->last_node)
			flag = 1;
		if (chunk == 1 && temp->data <= all->median)
			push(&all->b, &all->a);
		else if (chunk == 2 && temp->data > all->median)
			push(&all->b, &all->a);
		else if (temp->data == all->min)
			break ;
		else
			rotate(all, A);
		if (flag == 1)
			break ;
		temp = all->a;
	}
	reset(all->ops);
}

void	do_rotate(t_data *all, t_operations *ops)
{
	check_big(all, ops);
	check_small(all, ops);
	push(&all->a, &all->b);
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

void	do_sorting(t_data *all, t_operations *ops)
{
	find_values(all, B);
	define_operations(all, ops, B);
	if (all->b && (ops->rotate_big >= 0 || ops->reverse_big >= 0
			|| ops->rotate_small >= 0 || ops->reverse_small >= 0))
		push_stack(all, all->b);
}

/*
** sort_medium sorts stacks with 100 integers or less. 
*/

void	sort_medium(t_data *all)
{
	t_operations	ops;
	int				chunk;

	init_operations(all, &ops);
	chunk = 1;
	median(all, A);
	while (all->a)
	{
		push_chunk(all, chunk);
		while (all->b)
			do_sorting(all, &ops);
		while (ops.tracker)
		{
			rotate(all, A);
			ops.tracker--;
		}
		chunk++;
		if (chunk == 3)
			break ;
	}
}
