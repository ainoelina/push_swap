/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 08:01:10 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/13 14:25:49 by avuorio       ########   odam.nl         */
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
	sort_stack(all);
//	print_stack(all, all->a, A, 'A');
//	print_stack(all, all->b, B, 'B');
}
