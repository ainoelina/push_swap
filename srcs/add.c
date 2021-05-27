/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 14:55:43 by avuorio       #+#    #+#                 */
/*   Updated: 2021/05/27 14:58:00 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_number(int number)
{
	t_list	*new;

	new = (t_list *)malloc_memory(sizeof(t_list));
	new->data = number;
	new->next = NULL;
	return (new);
}

void	add_to_tail(t_list **tail, t_list *node)
{
	t_list	*temp;

	temp = *tail;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
	temp = temp->next;
	temp->prev = *tail;
	*tail = temp;
}

void	add_to_stack(t_stack *a, t_list *node, char *str)
{
	while (*str)
	{
		printf("%c\n", *str);
		while (*str == ' ')
			str++;
		if (*str == '\0')
			break ;
		node = add_number(my_atoi(&*str));
		add_to_tail(&a->tail, node);
		if (*str == '-' || *str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
			str++;
	}
}
