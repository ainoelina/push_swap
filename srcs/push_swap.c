/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:45:44 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/09 08:31:28 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_numbers(t_stack *a, char *str)
{
	t_list	*new_node;

	new_node = NULL;
	while (*str == ' ')
		str++;
	if (!(is_digit(*str)) && *str != '-' && *str != '+')
		error_handling(INPUT_INVALID);
	a->head->data = my_atoi(str);
	if (a->head->data > 2147483647 || a->head->data < -2147483648)
		error_handling(INT_MAX_MIN);
	a->tail = a->head;
	if (*str == '-' || *str == '+')
		str++;
	while (is_digit(*str))
		str++;
	if (*str && *str != ' ')
		error_handling(INPUT_INVALID);
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
	check_duplicates(a->head);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		nb;

	if (argc < 2)
	{
		write(1, "Error\nInvalid arguments.\n", 26);
		return (0);
	}
	create_stack(&a, argc, argv);
	b.head = NULL;
	b.tail = NULL;
	solve(&a, &b);
	while (a.head)
	{
		printf("a stack: %i\n", a.head->data);
		a.head = a.head->next;
	}
	while (b.head)
	{
		printf("b stack: %i\n", b.head->data);
		b.head = b.head->next;
	}
}
