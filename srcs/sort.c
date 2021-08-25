/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 13:12:26 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/25 14:01:16 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_data *all)
{
	all->len = stack_len(all->a);
	if (!sorted(all->a))
	{
		if (all->len <= 5)
			sort_small(all, all->len);
		if (all->len > 5 && all->len <= 100)
			sort_medium(all);
	}
	else
		return ;
}
