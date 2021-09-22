/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 08:01:10 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/22 12:11:39 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free_all(all);
}
