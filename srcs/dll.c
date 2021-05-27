/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dll.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 11:45:58 by avuorio       #+#    #+#                 */
/*   Updated: 2021/05/27 12:23:05 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	size;
}				t_stack;

void	push(t_node **head, int data)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	temp->data = data;
	temp->next = (*head);
	temp->prev = NULL;
	if (*head != NULL)
		(*head)->prev = temp;
	(*head) = temp;
}

void	insert_after(t_node *previous, int data)
{
	t_node	*temp;

	if (previous == NULL)
		return ;
	temp = (t_node *)malloc(sizeof(t_node));
	temp->data = data;
	temp->next = previous->next;
	previous->next = temp;
	temp->prev = previous;
	if (temp->next != NULL)
		temp->next->prev = temp;
}

void	insert_last(t_node **head, int data)
{
	t_node	*temp;
	t_node	*last;

	temp = (t_node *)malloc(sizeof(t_node));
	last = *head;
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

int	main(int argc, char **argv)
{
	t_node	*head;

	head = NULL;
	push(&head, 10);
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	t_node *temp;
	temp = head;
	while (temp != NULL)
	{
		printf("stack: %i\n", temp->data);
		temp = temp->next;
	}
	insert_last(&head, 11);
	insert_last(&head, 12);
	temp = head;
	while (temp != NULL)
	{
		printf("stack: %i\n", temp->data);
		temp = temp->next;
	}
}
