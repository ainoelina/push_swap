/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 08:06:29 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/15 14:44:14 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_input(t_all *all, char *str)
{
	int	data;

	while (*str)
	{
		while (*str == ' ')
			str++;
		if (!(is_digit(*str)) && *str != ' ' && *str != '-' && *str != '+')
			error_handling(INPUT_INVALID, all);
		if ((*str == '-' || *str == '+') && (!is_digit(*(str + 1))
				&& (*(str - 1) != ' ')))
			error_handling(INPUT_INVALID, all);
		if (is_digit(*str) && !is_digit(*(str + 1)) && (*(str + 1) != ' ')
			&& (*(str + 1) != '\0'))
			error_handling(INPUT_INVALID, all);
		data = my_atoi(str);
		if (data > MAX_INT || data < MIN_INT)
			error_handling(INPUT_INVALID, all);
		insert_last(all, A, data);
		if (*str == '-' || *str == '+')
			str++;
		while (is_digit(*str))
			str++;
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
