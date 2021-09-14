/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialise.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 15:45:42 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/14 14:37:26 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset(t_operations *ops)
{
	ops->r_big = 0;
	ops->rr_big = 0;
	ops->r_small = 0;
	ops->rr_small = 0;
	ops->big = 0;
	ops->small = 0;
}

void	init_operations(t_all *all, t_operations *ops)
{
	ops->big = 0;
	ops->small = 0;
	ops->r_big = 0;
	ops->r_small = 0;
	ops->rr_small = 0;
	ops->rr_big = 0;
	ops->tracker = 0;
	ops->counter = 0;
	all->ops = ops;
}

t_all	*init_struct(t_all *all, char **argv)
{
	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		error_handling(MALLOC_FAIL, all);
	all->a = NULL;
	all->b = NULL;
	all->last_node = NULL;
	all->argv = argv;
	all->min = 0;
	all->max = 0;
	all->len = 0;
	all->median = 0;
	return (all);
}
