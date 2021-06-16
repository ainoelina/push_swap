/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_values.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 13:35:34 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/16 14:08:53 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_small(t_data *all, int stack)
{
	t_list	*temp;

	if (stack == A)
		temp = all->a;
	if (stack == B)
		temp = all->b;
	all->small = all->big;
	while (temp)
	{
		if (temp->data <= all->small)
			all->small = temp->data;
		temp = temp->next;
	}
}

void	find_big(t_data *all, int stack)
{
	t_list	*temp;

	if (stack == A)
		temp = all->a;
	else if (stack == B)
		temp = all->b;
	all->big = temp->data;
	while (temp)
	{
		if (temp->data > all->big)
			all->big = temp->data;
		temp = temp->next;
	}
}

void	find_values(t_data *all, int stack)
{
	find_big(all, stack);
	printf("biggest is %i\n", all->big);
	find_small(all, stack);
	printf("smallest is %i\n", all->small);
}
