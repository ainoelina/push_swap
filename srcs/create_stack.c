/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 08:06:29 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/14 14:38:09 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_input(t_all *all, char *str)
{
	int	data;
	int	i;

	i = 0;
	while (*str)
	{
		while (i != 0 && *str && *str == ' ')
			str++;
		while (*(str + i) && (*(str + i) == '-' || (*(str + i) == '+'
					|| is_digit(*(str + i)))))
			i++;
		if (!*str)
			break ;
		data = my_atoi(str);
		if (data > MAX_INT || data < MIN_INT)
			error_handling(INPUT_INVALID, all);
		insert_last(all, A, data);
		str = str + i;
	}
}

void	create_stack(t_all *all, int argc, char **argv)
{
	int	i;

	i = 1;
	check_input(all);
	while (i < argc)
	{
		parse_input(all, argv[i]);
		i++;
	}
	if (!all->a)
		error_handling(INPUT_INVALID, all);
	check_duplicates(all->a, all);
}
