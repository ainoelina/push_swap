/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 08:44:45 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/10 11:15:18 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_adding(t_list **top, t_list *temp, int data)
{
	if (*top)
	{
		temp = (t_list *)malloc(sizeof(t_list));
		if (!temp)
			error_handling(MALLOC_FAIL);
		temp->next = *top;
		temp->prev = (*top)->prev;
		(*top)->prev = temp;
		temp->prev->next = temp;
		temp->data = data;
	}
	else
	{
		*top = (t_list *)malloc(sizeof(t_list));
		if (!*top)
			error_handling(MALLOC_FAIL);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->data = data;
		(*top)->next->next = NULL;
	}
}

void	add_to_tail(t_data *all, int stack, int data)
{
	t_list	*temp;
	t_list	**top;	

	if (stack == A)
		top = &all->a;
	if (stack == B)
		top = &all->b;
	do_adding(top, temp, data);
}


void	insert_last(t_data *all, int stack, int data)
{
	t_list	**head;
	t_list	*temp;
	t_list	*last;

	if (stack == A)
		head = &all->a;
	if (stack == B)
		head = &all->b;
	temp = (t_list *)malloc(sizeof(t_list));
	last = all->a;
	temp->data = data;
	temp->next = NULL;
	if (*head == NULL)
	{
		temp->prev = NULL;
		*head = temp;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	temp->prev = last;
}
