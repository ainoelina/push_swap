/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   median.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 10:36:32 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/22 12:20:48 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *array, int count)
{
	int	i;
	int	j;
	int	save;

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

/*
** the median value and quarter chunks are used mainly for the
** medium and big sort functions. they make the sorting of the
** stack easier by dividing the values into smaller groups to sort.
*/

void	find_median(int *array, int count, t_all *all)
{
	int	quarter;

	quarter = count / 4;
	all->median = array[quarter * 2];
	all->quarter_1 = array[quarter];
	all->quarter_3 = array[quarter * 3];
}

/*
** the median value is calculated by copying the values in the stack
** into an array. the array is then sorted and median is calculated
** in find_median function.
*/

void	median(t_all *all, int stack)
{
	t_list	*temp;
	int		*array;
	int		count;
	int		len;

	if (stack == A)
		temp = all->a;
	else
		temp = all->b;
	len = stack_len(all);
	array = (int *)malloc(sizeof(int) * (len + 1));
	if (!array)
		error_handling(all);
	count = 0;
	while (count < len)
	{
		array[count] = temp->data;
		temp = temp->next;
		count++;
	}
	sort_array(array, count);
	find_median(array, count, all);
	free(array);
}
