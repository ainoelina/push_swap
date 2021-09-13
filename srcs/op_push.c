/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 13:18:29 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/13 14:29:28 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **dest, t_list **src, int op)
{
	t_list	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dest)
		(*dest)->prev = temp;
	temp->next = *dest;
	*dest = temp;
	(*dest)->prev = NULL;
	if (op == PA)
		write(1, "pa\n", 4);
	else if (op == PB)
		write(1, "pb\b", 4);
}
