/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 13:12:26 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/16 13:16:52 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_data *all)
{
	int	len;

	len = stack_len(all->a);
	if (!sorted(all->a))
	{
		if (len <= 5)
			sort_small(all, len);
		// if (len > 5 && len <= 100)
		// 	sort_medium(all);
		// else
		// 	sort_big(all);
	}
	else
		return ;
}
