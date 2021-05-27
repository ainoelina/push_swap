/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:45:44 by avuorio       #+#    #+#                 */
/*   Updated: 2021/05/27 14:46:35 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_number(int number)
{
	t_list	*new;

	new = (t_list *)malloc_memory(sizeof(t_list));
	new->data = number;
	new->next = NULL;
	return (new);
}

void	add_to_tail(t_list **tail, t_list *node)
{
	t_list	*temp;

	temp = *tail;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
	temp = temp->next;
	temp->prev = *tail;
	*tail = temp;
}

void	add_to_stack(t_stack *a, t_list *node, char *str, int *i)
{
	while (str[*i])
	{
		printf("%c\n", str[*i]);
		while (str[*i] == ' ')
			(*i)++;
		if (str[*i] == '\0')
			break ;
		node = add_number(my_atoi(&str[*i]));
		add_to_tail(&a->tail, node);
		if (str[*i] == '-' || str[*i] == '+')
			(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
	}
}

void	parse_numbers(t_stack *a, char *str)
{
	int		i;
	t_list	*new_node;

	new_node = NULL;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '-' && str[i] != '+')
		exit(0);
	a->head->data = my_atoi(&str[i]);
	if (a->head->data > 2147483647 || a->head->data < -2147483648)
		exit(0);
	a->tail = a->head;
//	printf("a->data now %i\nstring %s\n", a->head->data, str);
	add_to_stack(a, new_node, str, &i);
}

void	parse_rest(t_stack *a, char *str)
{
	int		i;
	t_list	*new_node;

	new_node = NULL;
	i = 0;
	add_to_stack(a, new_node, str, &i);
}

void	create_stack(t_stack *a, int argc, char **argv)
{
	 int	i;

//	printf("argv %s\n", argv[1]);
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
	// t_list *temp;
	// printf("a head data %i\n", a.head->data);
	// temp = a.head->next;
	// printf("temp data %i\n", temp->data);
	while (a.head->next != NULL)
	{
		printf("stack: %i\n", a.head->data);
		a.head = a.head->next;
	}
}
