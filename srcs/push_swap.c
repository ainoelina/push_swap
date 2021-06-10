/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 08:01:10 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/10 12:19:23 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *list);

int	main(int argc, char **argv)
{
	t_data	all;

	if (argc < 2)
	{
		write(1, "Error\nInvalid arguments.\n", 26);
		return (0);
	}
	create_stack(&all, argc, argv);
	print_stack(all.a);
//	solve(all);
}

void	print_stack(t_list *list)
{
	int i;

	i = 1;
	while (list != NULL)
	{
		printf("%3i: %i\n", i, list->data);
		list = list->next;
		i++;
	}
}
