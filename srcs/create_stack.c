/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 08:06:29 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/25 16:13:45 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_input(t_data *all, t_list *a, char *str)
{
	int	data;

	while (*str)
	{
		while (*str == ' ')
			str++;
		if (!(is_digit(*str)) && *str != ' ' && *str != '-' && *str != '+')
			error_handling(INPUT_INVALID);
		if ((*str == '-' || *str == '+') && (!is_digit(*(str + 1))
				&& (*(str - 1) != ' ')))
			error_handling(INPUT_INVALID);
		if (is_digit(*str) && !is_digit(*(str + 1)) && (*(str + 1) != ' ')
			&& (*(str + 1) != '\0'))
			error_handling(INPUT_INVALID);
		data = my_atoi(str);
		if (data > MAX_INT || data < MIN_INT)
			error_handling(INPUT_INVALID);
		insert_last(all, A, data);
		if (*str == '-' || *str == '+')
			str++;
		while (is_digit(*str))
			str++;
	}
}

void	create_stack(t_data *all, int argc, char **argv)
{
	int	i;

	i = 1;
	init_struct(all, argv);
	check_input(all);
	while (i < argc)
	{
		parse_input(all, all->a, argv[i]);
		i++;
	}
	check_duplicates(all->a);
}
