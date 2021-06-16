/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 13:18:29 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/16 12:41:52 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **dest, t_list **src, t_data *all)
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
}
