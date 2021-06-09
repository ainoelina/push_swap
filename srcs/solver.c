/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 13:23:54 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/09 09:27:02 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_stack *a, t_stack *b)
{
	int	len;

	len = stack_len(a->head);
//	if (!sorted)
//	{
		if (len <= 5)
			sort_five(a, b, len);
//		if (len <= 100)
//			sort_hundred(&a, &b);
//		else
//			sort_more(&a, &b);
//	}
}
