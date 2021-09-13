/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   median.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 10:36:32 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/13 10:58:21 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_array(int *array, int count)
{
	int i;
	int j;
	int save;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count - 1)
		{
			if (array[j] > array[j + 1])
			{
				save = array[j];
				array[j] = array[j + 1];
				array[j + 1] = save;
			}
			j++;
		}
		i++;
	}
}

void find_median(int *array, int count, t_all *all)
{
	int quarter;

	quarter = count / 4;
	all->median = array[quarter * 2];
}

/*
** the median value is calculated by copying the values in the stack
** into an array. the array is then sorted and median is calculated
** in find_median function.
*/

void median(t_all *all, int stack)
{
	t_list *temp;
	int *array;
	int count;

	if (stack == A)
		temp = all->a;
	if (stack == B)
		temp = all->b;
	array = (int *)malloc(sizeof(int) * (all->len + 1));
	if (!array)
		error_handling(MALLOC_FAIL, all);
	count = 0;
	while (count < all->len)
	{
		array[count] = temp->data;
		temp = temp->next;
		count++;
	}
	sort_array(array, count);
	find_median(array, count, all);
	free(array);
	printf("median is %i\n", all->median);
}
