/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 12:53:04 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/22 12:13:58 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	my_atoi(char *str)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	n = n * sign;
	return (n);
}

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

int	sorted(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp && temp->next)
	{
		if (temp == a->prev)
			break ;
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}
