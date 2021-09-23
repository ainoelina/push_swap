/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 08:01:10 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/23 10:08:56 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push_swap checks for the arguments sent to the program, and then fills
** the stack with input. sort_stack function then sorts the stack.
*/

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc < 2)
	{
		write(1, "Error\n", 5);
		return (0);
	}
	all = NULL;
	all = init_all(all, argv);
	create_stack(all, argc, argv);
	sort_stack(all);
	while (1){};
	free_all(all);
}
