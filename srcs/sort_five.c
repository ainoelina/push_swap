/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_five.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/09 08:41:49 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/09 09:27:57 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_5(t_stack *a, t_stack *b)
{
}

void	case_2(t_stack *a)
{
	if (a->head->data > a->head->next->data)
		swap(&a->head);
}

void	case_3(t_stack *a)
{
	int	top;
	int	middle;
	int	bottom;

	top = a->head->data;
	middle = a->head->next->data;
	bottom = a->tail->data;
	if (top > middle && middle < bottom && bottom > top)
		swap(&a->head);
	if (top > middle && middle < bottom && top > bottom)
		rotate(&a->head, &a->tail);
	if (top < middle && middle > bottom && top > bottom)
		reverse_rotate(&a->head, &a->tail);
	if (top > middle && middle > bottom && bottom < top)
	{
		swap(&a->head);
		reverse_rotate(&a->head, &a->tail);
	}
	if (top < middle && middle > bottom && bottom > top)
	{
		swap(&a->head);
		rotate(&a->head, &a->tail);
	}
}

void	case_4(t_stack *a, t_stack *b)
{
	t_list	*temp;

	temp = a->head;
	find_values(a, b, A);
	printf("big is %i, small is %i\n", a->big, a->small);
}

void	sort_five(t_stack *a, t_stack *b, int stacklen)
{
	if (stacklen == 2)
		case_2(a);
	if (stacklen == 3)
		case_3(a);
	if (stacklen == 4)
		case_4(a, b);
//	if (stacklen == 5)
//		case_5(a, b);
}
