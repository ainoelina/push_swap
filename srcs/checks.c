/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 09:07:03 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/15 14:39:53 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handling(int error, t_all *all)
{
	if (error == INPUT_INVALID)
		write(1, "Error\nInvalid argument input.", 30);
	if (error == DUPLICATE_ARGS)
		write(1, "Error\nDuplicate integer(s) in arguments.", 41);
	if (error == MALLOC_FAIL)
		write(1, "Error\nMallocing failed.\n", 25);
	free(all->a);
	exit(0);
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
				error_handling(DUPLICATE_ARGS, all);
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
				error_handling(INPUT_INVALID, all);
		}
		i++;
		input = all->argv[i];
	}
}
