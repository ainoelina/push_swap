/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialise.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 15:45:42 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/25 16:13:10 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_struct(t_data *all, char **argv)
{
	t_operations	ops;

	all->a = NULL;
	all->b = NULL;
	all->argv = argv;
	all->min = 0;
	all->max = 0;
	all->len = 0;
	ops.big = 0;
	ops.small = 0;
	all->ops = &ops;
}
