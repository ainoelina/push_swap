/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 11:19:36 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/03 14:07:10 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** sa - swap 2 elements on top of stack a
** sb - swap 2 elements on top of stack b
** ss - swap a and b at the same time
** pa - push a: take top element from b and put at the top of a.
** pb - push b: take top element from a and put at the top of b.
** ra - rotate a: shift up all elements of stack a by 1.
** rb - rotate b: shift up all elements of stack b by 1.
** rr - rotate a and b at the same time.
** rra - reverse rotate a: shift down all elements by 1.
** rrb - reverse rotate b: shift down all elements by 1.
** rrr - reverse rotate both a and be at the same time.
*/

void	swap(t_list **dll)
{
	t_list	*temp;

	if (!(*dll) || !(*dll)->next)
		return ;
	temp = *dll;
	*dll = (*dll)->next;
	temp->next = (*dll)->next;
	temp->prev = *dll;
	(*dll)->next = temp;
	(*dll)->prev = NULL;
}

void	push(t_list **dst, t_list **src)
{
	t_list	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dst)
		(*dst)->prev = temp;
	temp->next = *dst;
	*dst = temp;
	(*dst)->prev = NULL;
}

void	rotate(t_list **head, t_list **tail)
{
	if (*head == NULL)
		return ;
	(*tail)->next = *head;
	(*head)->prev = *tail;
	*head = (*head)->next;
	(*head)->prev = NULL;
	*tail = (*tail)->next;
	(*tail)->next = NULL;
}

void	reverse_rotate(t_list **head, t_list **tail)
{
	if (*head == NULL || *tail == NULL)
		return ;
	(*head)->prev = *tail;
	(*tail)->next = *head;
	*head = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	(*head)->prev = NULL;
}
