/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 08:01:10 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/10 14:28:02 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	all;

	if (argc < 2)
	{
		write(1, "Error\nInvalid arguments.\n", 26);
		return (0);
	}
	create_stack(&all, argc, argv);
	print_address(&all.a, "stack a");
	print_address(&all.b, "stack b");
	t_list *temp = all.a;
	print_address(temp, "temp");
	push_stack(&all.a, &all.b, &all);
	print_address(temp, "temp after");
//	sort_stack(all);
	print_stack(all.a);
	print_stack(all.b);
//	solve(all);
}
