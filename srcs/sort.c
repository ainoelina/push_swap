/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 13:12:26 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/21 11:15:26 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_all *all)
{
	t_operations	ops;

	init_operations(all, &ops);
	all->len = stack_len(all);
	if (!sorted(all->a))
	{
		if (all->len <= 5)
			sort_small(all, all->len);
		if (all->len > 5 && all->len <= 100)
			sort_medium(all, all->ops);
	}
	else
		return ;
}
