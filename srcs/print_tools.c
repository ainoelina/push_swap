/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 13:09:59 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/30 12:32:46 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_address(void *p, char *str)
{
	printf("%s add: %p\n", str, p);
}

void	print_data(char *str, int data)
{
	printf("%s %i\n", str, data);
}

void	print_stack(t_list *list, int stack)
{
	int		i;

	i = 1;
	while (list != NULL)
	{
		if (stack == A)
			printf("A: %3i: %i, add: %p\n", i, list->data, list);
		else
			printf("B: %3i: %i, add: %p\n", i, list->data, list);
		list = list->next;
		i++;
	}
}

void	print_values(t_data *all)
{
	print_data("big rotate:", all->ops->rotate_big);
	print_data("big reverse:", all->ops->reverse_big);
	print_data("small rotate:", all->ops->rotate_small);
	print_data("small reverse:", all->ops->reverse_small);
}
