/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialise.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 15:45:42 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/30 13:04:20 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset(t_operations *ops)
{
	ops->rotate_big = 0;
	ops->reverse_big = 0;
	ops->rotate_small = 0;
	ops->reverse_small = 0;
	ops->big = 0;
	ops->small = 0;
}

void	init_operations(t_data *all, t_operations *ops)
{
	ops->big = 0;
	ops->small = 0;
	ops->rotate_big = 0;
	ops->rotate_small = 0;
	ops->reverse_small = 0;
	ops->reverse_big = 0;
	ops->tracker = 0;
	all->ops = ops;
}

void	init_struct(t_data *all, char **argv)
{
	all->a = NULL;
	all->b = NULL;
	all->last_node = NULL;
	all->argv = argv;
	all->min = 0;
	all->max = 0;
	all->len = 0;
}
