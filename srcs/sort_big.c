/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 12:12:27 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/15 12:21:57 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_all *all, t_operations *ops)
{
	int	chunk;

	chunk = 1;
	median(all, A);
	while (all->a)
	{
		push_chunks_big(all, all->a, chunk);
	}
}
