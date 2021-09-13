/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 13:09:59 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/13 14:23:13 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_address(void *p, char *str)
{
	printf("%s add: %p\n", str, p);
}

void	print_data(char *str, int data)
{
	printf("%s %i\n", str, data);
}

void   print_stack(t_all *all, t_list *list, int stack, char c)
{
	t_list	*temp;
	int		i;
	t_list	*end;

	i = 1;
	if (!list)
		return ;
	if (stack == A)
	{
		temp = all->a;
		end = all->a->prev;
	}
	else
	{
		temp = all->b;
		end = all->b->prev;
	}
	while (temp)
	{
		printf("%c - %i: %i (%p)\n", c, i, temp->data, temp);
		if (temp == list->prev)
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
