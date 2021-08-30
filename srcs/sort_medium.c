/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_medium.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/23 13:10:50 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/30 10:49:00 by avuorio       ########   odam.nl         */
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
	t_list	*end;
	int		check;
	int		steps;

	check = 0;
	steps = stack_len(all->a);
	temp = all->a;
	find_values(all, A);
	while (1)
	{
		if (check == steps)
			break ;
		if (chunk == 1 && temp->data <= all->median)
			push(&all->b, &all->a, all);
//		else if (temp->data == all->small)
//			break ;
		else
			rotate(all, A);
		check++;
		temp = all->a;
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
		}
		printf("first push completed\n");
		break ;
	}
}
