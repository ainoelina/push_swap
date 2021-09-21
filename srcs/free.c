/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 08:47:05 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/21 09:14:44 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*next;
	t_list	*empty;

	if (stack)
	{
		next = stack->next;
		while (next != stack)
		{
			empty = next;
			next = next->next;
			free(empty);
		}
		free(next);
	}
}

void	free_all(t_all *all)
{
	if (all)
	{
		if (all->a)
			free_stack(all->a);
		if (all->b)
			free_stack(all->b);
		free(all);
	}
}
