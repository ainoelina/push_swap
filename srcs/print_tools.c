/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 13:09:59 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/14 14:36:02 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_data(char *str, int data)
{
	printf("%s %i\n", str, data);
}

void	print_stack(t_list *list, char c)
{
	t_list	*temp;
	t_list	*stop;
	int		i;

	if (!list)
		return ;
	i = 1;
	temp = list;
	stop = list->prev;
	printf("\n~~~~~ sorted stack ~~~~~\n");
	while (temp)
	{
		printf("%c - %i: %-10i (%p)\n", c, i, temp->data, temp);
		if (temp == stop)
			break ;
		temp = temp->next;
		i++;
	}
}

void	print_values(t_all *all)
{
	print_data("big rotate:", all->ops->r_big);
	print_data("big reverse:", all->ops->rr_big);
	print_data("small rotate:", all->ops->r_small);
	print_data("small reverse:", all->ops->rr_small);
}
