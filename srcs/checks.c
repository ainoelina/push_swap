/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 09:07:03 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/22 12:08:31 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handling(t_all *all)
{
	write(1, "Error\n", 5);
	free_all(all);
	exit(1);
}

void	check_duplicates(t_list *list, t_all *all)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = list;
	while (temp1 != list->prev)
	{
		temp2 = temp1->next;
		while (temp2 != list)
		{
			if (temp1->data == temp2->data)
				error_handling(all);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void	check_input(t_all *all)
{
	char	*input;
	int		i;

	i = 1;
	input = all->argv[i];
	while (input)
	{
		while (*input)
		{
			if (*input == ' ' || is_digit(*input))
				input++;
			else if ((*input == '-' || *input == '+') && is_digit(*(input + 1))
				&& (input == all->argv[i] || *(input - 1) == ' '))
				input++;
			else
				error_handling(all);
		}
		i++;
		input = all->argv[i];
	}
}
