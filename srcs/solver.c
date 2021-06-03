/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 13:23:54 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/03 14:08:19 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3(t_stack *a, t_stack *b)
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
	printf("number are top: %i, middle: %i, bottom: %i\n", top, middle, bottom);
}

void	choose_algorithm(t_stack *a, t_stack *b, int len)
{
	if (len <= 3)
		case_3(a, b);
}
