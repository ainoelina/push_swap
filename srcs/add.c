/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 08:44:45 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/15 14:04:52 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_top(t_all *all, t_list **head, t_list *temp, int data)
{
	if (*head)
	{
		temp = (t_list *)malloc(sizeof(t_list));
		if (!temp)
			error_handling(MALLOC_FAIL, all);
		temp->next = *head;
		temp->prev = (*head)->prev;
		(*head)->prev = temp;
		temp->prev->next = temp;
		temp->data = data;
		*head = (*head)->prev;
	}
	else
	{
		*head = (t_list *)malloc(sizeof(t_list));
		if (!*head)
			error_handling(MALLOC_FAIL, all);
		(*head)->next = *head;
		(*head)->prev = (*head);
		(*head)->data = data;
	}
}

void	insert_top(t_all *all, int stack, int data)
{
	t_list	**head;
	t_list	*temp;

	temp = NULL;
	if (stack == A)
		head = &all->a;
	else
		head = &all->b;
	add_top(all, head, temp, data);
}

void	delete_top(t_all *all, int stack)
{
	t_list	**top;
	t_list	*temp;

	if (stack == A)
		top = &all->a;
	else
		top = &all->b;
	if (*top)
	{
		if ((*top)->next == *top)
		{
			free(*top);
			*top = NULL;
		}
		else
		{
			temp = *top;
			*top = (*top)->next;
			temp->prev->next = *top;
			(*top)->prev = temp->prev;
			free(temp);
		}
	}
}

void	add_last(t_all *all, t_list **head, t_list *temp, int data)
{
	if (*head)
	{
		temp = (t_list *)malloc(sizeof(t_list));
		if (!temp)
			error_handling(MALLOC_FAIL, all);
		temp->next = *head;
		temp->prev = (*head)->prev;
		(*head)->prev = temp;
		temp->prev->next = temp;
		temp->data = data;
	}
	else
	{
		*head = (t_list *)malloc(sizeof(t_list));
		if (!head)
			error_handling(MALLOC_FAIL, all);
		(*head)->next = *head;
		(*head)->prev = *head;
		(*head)->data = data;
	}	
}

void	insert_last(t_all *all, int stack, int data)
{
	t_list	**head;
	t_list	*temp;

	temp = NULL;
	if (stack == A)
		head = &all->a;
	else
		head = &all->b;
	add_last(all, head, temp, data);
}
