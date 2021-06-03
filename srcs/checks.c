/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 09:07:03 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/03 11:11:30 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handling(int error)
{
	if (error == INPUT_INVALID)
		write(1, "Error\nInvalid argument input.", 30);
	if (error == INT_MAX_MIN)
		write(1, "Error\nArgument bigger/smaller than an integer.", 47);
	if (error == DUPLICATE_ARGS)
		write(1, "Error\nDuplicate integer(s) in arguments.", 41);
	exit(0);
}

void	check_duplicates(t_list *head)
{
	t_list	*lst1;
	t_list	*lst2;
	int		num;

	lst1 = head;
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
