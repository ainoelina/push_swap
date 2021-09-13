/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 12:53:04 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/13 13:32:39 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_all *all)
{
	t_list	*temp;
	int		len;

	len = 0;
	temp = all->a;
	while (temp)
	{
		len++;
		if (temp == all->a->prev)
			break ;
		temp = temp->next;
	}
	return (len);
}

int	get_position(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (*str && (*str == '-' || *str == '+' || is_digit(*str)))
			i++;
	}
	return (i);
}

int	sorted(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp && temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	printf("sorted!\n");
	return (1);
}

void	last_node(t_all *all, int stack)
{
	t_list	*temp;

	if (stack == A)
		temp = all->a;
	else
		temp = all->b;
	while (temp != NULL)
	{
		if (temp->next == NULL)
			all->last_node = temp;
		temp = temp->next;
	}
}
