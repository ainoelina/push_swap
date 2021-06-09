/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_values.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/09 08:56:26 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/09 09:31:11 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_small(t_list *stack, int big)
{
	t_list	*temp;
	t_list	*end;
	int		smallest;

	temp = stack;
	end = stack->prev;
	smallest = big;
	while (stack)
	{
		if (temp->data <= smallest)
			smallest = temp->data;
		if (temp == end)
			break ;
		temp = temp->next;
	}
	return (smallest);
}

int	find_big(t_stack *stack)
{
	t_list	*temp;
	t_list	*end;
	int		biggest;

	temp = stack->head;
	biggest = temp->data;
	end = stack->tail;
	while (stack)
	{
		if (temp->data > biggest)
		{
			biggest = temp->data;
			printf("biggest now %i\n", biggest);
		}
		if (temp == end)
			break ;
		temp = temp->next;
	}
	return (biggest);
}

void	find_values(t_stack *a, t_stack *b, int stack)
{
	if (stack == A)
	{
		a->big = find_big(a);
		a->small = find_small(a->head, a->big);
	}
	if (stack == B)
	{
		b->big = find_big(b);
		b->small = find_small(b->head, b->big);
	}
}
