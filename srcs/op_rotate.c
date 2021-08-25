/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 12:33:43 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/25 11:52:06 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_data *all, int stack)
{
	if (stack == A)
	{
		if (all->a)
		{
			insert_last(all, A, all->a->data);
			all->a = all->a->next;
			all->a->prev = NULL;
		}
	}
	if (stack == B)
	{
		if (all->b)
		{
			insert_last(all, B, all->b->data);
			all->b = all->b->next;
			all->b->prev = NULL;
		}
	}
}

void	rotate_a(t_list **a)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *a;
	temp1 = temp1->next;
	if (temp1 == NULL)
		return ;
	temp2 = temp1;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	temp1->next = *a;
	(*a)->prev = temp1;
	temp2->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*prev;
	t_list	*last;

	head = *stack;
	last = head;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = head;
	prev->next = NULL;
	*stack = last;
}

void	rotate_ab(t_data *all)
{
	rotate(all, A);
	rotate(all, B);
}
