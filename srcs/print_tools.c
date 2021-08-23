/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 13:09:59 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/23 09:55:05 by avuorio       ########   odam.nl         */
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

void	print_stack(t_list *list)
{
	int		i;

	i = 1;
	while (list != NULL)
	{
		printf("%3i: %i, add: %p\n", i, list->data, list);
		list = list->next;
		i++;
	}
}
