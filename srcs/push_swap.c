/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 08:01:10 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/23 09:55:12 by avuorio       ########   odam.nl         */
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
	sort_stack(&all);
	print_stack(all.a);
	print_stack(all.b);
}
