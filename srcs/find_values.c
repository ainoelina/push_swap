/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_values.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 13:35:34 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/30 14:22:29 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_data *all, int stack)
{
	t_list	*temp;

	if (stack == A)
		temp = all->a;
	else
		temp = all->b;
	all->min = all->max;
	while (temp)
	{
		if (temp->data <= all->min)
			all->min = temp->data;
		temp = temp->next;
	}
}

void	find_max(t_data *all, int stack)
{
	t_list	*temp;

	if (stack == A)
		temp = all->a;
	else
		temp = all->b;
	all->max = temp->data;
	while (temp)
	{
		if (temp->data > all->max)
			all->max = temp->data;
		temp = temp->next;
	}
}

void	find_values(t_data *all, int stack)
{
	find_max(all, stack);
	find_min(all, stack);
}
