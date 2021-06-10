/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 13:18:29 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/10 14:26:33 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_data *all, int dest)
{
	int	temp_data;

	if (dest == A)
	{
		if (all->b)
		{
			temp_data = all->a->data;
			delete_top(all, B);
			insert_top(all, A, temp_data);
		}
	}
	if (dest == B)
	{
		if (all->a)
		{
			temp_data = all->a->data;
			delete_top(all, A);
			insert_top(all, B, temp_data);
		}
	}
}

void	push_stack(t_list **dest, t_list **src, t_data *all)
{
	t_list **temp;

	print_address(dest, "destination");
	print_address(src, "source");
	if (!src)
		return ;
}