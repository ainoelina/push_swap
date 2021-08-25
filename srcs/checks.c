/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 09:07:03 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/25 15:34:24 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handling(int error)
{
	if (error == INPUT_INVALID)
		write(1, "Error\nInvalid argument input.", 30);
	if (error == DUPLICATE_ARGS)
		write(1, "Error\nDuplicate integer(s) in arguments.", 41);
	if (error == MALLOC_FAIL)
		write(1, "Error\nMallocing failed.\n", 25);
	exit(0);
}

void	check_duplicates(t_list *list)
{
	t_list	*lst1;
	t_list	*lst2;
	int		num;

	lst1 = list;
	while (lst1)
	{
		num = lst1->data;
		lst2 = lst1;
		while (lst2->next)
		{
			if (lst2->next->data == num)
				error_handling(DUPLICATE_ARGS);
			lst2 = lst2->next;
		}
		lst1 = lst1->next;
	}
}

void	check_input(t_data *all)
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
				error_handling(INPUT_INVALID);
		}
		i++;
		input = all->argv[i];
	}
}
