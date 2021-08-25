/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   define_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 14:11:55 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/25 16:26:11 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	define_operations(t_data *all, int stack)
{
	move_small(all, all->ops, B);
	move_big(all, all->ops, B);
}
