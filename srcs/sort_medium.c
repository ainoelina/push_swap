/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_medium.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/23 13:10:50 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/22 11:47:12 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push_part function loops trough the stack and pushes all values
** smaller/bigger or equal to median to the stack b, depending on 
** the part number.
*/

void	push_part(t_all *all, int part)
{
	t_list	*temp;
	t_list	*end;
	int		flag;

	flag = 0;
	temp = all->a;
	end = all->a->prev;
	find_values(all, A);
	while (1)
	{
		if (temp == end)
			flag = 1;
		if (part == 1 && temp->data <= all->median)
			push(all, PB);
		else if (part == 2 && temp->data > all->median)
			push(all, PB);
		else if (temp->data == all->min)
			break ;
		else
			rotate(all, A, RA);
		if (flag == 1)
			break ;
		temp = all->a;
	}
	reset(all, all->ops);
}

void	do_rotate(t_all *all, t_operations *ops)
{
	check_big(all, ops);
	check_small(all, ops);
	push(all, PA);
	if (ops->small)
		rotate(all, A, RA);
	if (ops->big || !all->b)
		ops->tracker++;
	reset(all, ops);
}

void	push_stack(t_all *all, t_list *stack)
{
	t_list	*end;

	end = stack->prev;
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
		if (stack == end)
			break ;
		stack = all->b;
	}
}

void	do_sorting(t_all *all, t_operations *ops)
{
	find_values(all, B);
	define_operations(all, ops, all->b);
	if (all->b && (ops->r_big >= 0 || ops->rr_big >= 0 || ops->r_small >= 0
			|| ops->rr_small >= 0))
		push_stack(all, all->b);
}

/*
** sort_medium sorts stacks with 100 integers or less by finding median
** and then pushing lower/higher values to stack b. 
*/

void	sort_medium(t_all *all, t_operations *ops)
{
	int	part;

	part = 1;
	median(all, A);
	while (all->a)
	{
		push_part(all, part);
		while (all->b)
			do_sorting(all, all->ops);
		while (ops->tracker)
		{
			ops->tracker--;
			if (ops->tracker == 0)
				break ;
			rotate(all, A, RA);
		}
		part++;
		if (part == 3)
			break ;
	}
}
