/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 13:12:26 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/22 12:56:02 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_all *all)
{
	t_operations	ops;
	int				len;

	len = stack_len(all);
	init_operations(all, &ops);
	if (!sorted(all->a))
	{
		if (len <= 5)
			sort_small(all, len);
		else if (len <= 100)
			sort_medium(all, all->ops);
		else
			sort_big(all, all->ops);
	}
}
