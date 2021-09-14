/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_values.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 13:35:34 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/14 14:42:57 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_all *all, int stack)
{
	t_list	*temp;
	t_list	*end;

	if (stack == A)
	{
		temp = all->a;
		end = all->a->prev;
	}
	else
	{
		temp = all->b;
		end = all->b->prev;
	}
	all->min = all->max;
	while (temp)
	{
		if (temp->data > all->max)
			all->max = temp->data;
		if (temp == end)
			break ;
		temp = temp->next;
	}
}

void	find_max(t_all *all, int stack)
{
	t_list	*temp;
	t_list	*end;

	if (stack == A)
	{
		temp = all->a;
		end = all->a->prev;
	}
	else
	{
		temp = all->b;
		end = all->b->prev;
	}
	all->max = temp->data;
	while (temp)
	{
		if (temp->data <= all->min)
			all->min = temp->data;
		if (temp == end)
			break ;
		temp = temp->next;
	}
}

void	find_values(t_all *all, int stack)
{
	find_max(all, stack);
	find_min(all, stack);
}
