/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:45:44 by avuorio       #+#    #+#                 */
/*   Updated: 2021/05/27 15:04:49 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_numbers(t_stack *a, char *str)
{
	t_list	*new_node;

	new_node = NULL;
	while (*str == ' ')
		str++;
	if (!(*str >= '0' && *str <= '9') && *str != '-' && *str != '+')
		exit(0);
	a->head->data = my_atoi(str);
	if (a->head->data > 2147483647 || a->head->data < -2147483648)
		exit(0);
	a->tail = a->head;
	add_to_stack(a, new_node, str);
}

void	parse_rest(t_stack *a, char *str)
{
	t_list	*new_node;

	new_node = NULL;
	add_to_stack(a, new_node, str);
}

void	create_stack(t_stack *a, int argc, char **argv)
{
	 int	i;

	 i = 2;
	 a->head = malloc_memory(sizeof(t_list));
	 parse_numbers(a, argv[1]);
	 while (i < argc)
	{
		 parse_rest(a, argv[i]);
		 i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		nb;

	if (argc < 2)
	{
		write(1, "Error: invalid arguments.\n", 26);
		return (0);
	}
	create_stack(&a, argc, argv);
	while (a.head->next != NULL)
	{
		printf("stack: %i\n", a.head->data);
		a.head = a.head->next;
	}
}
