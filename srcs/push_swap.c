/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 08:01:10 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/15 14:47:40 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc < 2)
	{
		write(1, "Error\nInvalid arguments.\n", 26);
		return (0);
	}
	all = NULL;
	all = init_struct(all, argv);
	create_stack(all, argc, argv);
//	printf("~~~~~ operations ~~~~~\n");
	sort_stack(all);
//	printf("\n~~ number of instructions: %i ~~~~\n", all->ops->counter);
//	print_stack(all->a, 'A');
//	sorted(all->a);
}
