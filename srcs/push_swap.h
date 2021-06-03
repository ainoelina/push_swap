/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:44:15 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/03 13:57:52 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/*
** ~~~~~~~~ ERRORS ~~~
*/

# define INPUT_INVALID -1
# define INT_MAX_MIN -2
# define DUPLICATE_ARGS -3



typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct s_stack
{
	t_list	*head;
	t_list	*tail;
	int		top;
	int		argc;
}				t_stack;

/*
** ~~~~~~~~ OPERATIONS ~~~
*/
void	swap(t_list **dll);
void	push(t_list **dst, t_list **src);
void	rotate(t_list **head, t_list **tail);
void	reverse_rotate(t_list **head, t_list **tail);

void	choose_algorithm(t_stack *a, t_stack *b, int len);

void	add_to_stack(t_stack *a, t_list *node, char *str);

void	check_duplicates(t_list *head);

void	error_handling(int error);

/*
** ~~~~~~~~ UTILS ~~~
*/

void	*malloc_memory(size_t size);

int		ft_strlen(char *str);
int		my_atoi(char *str);
int		is_digit(int c);
int		stack_len(t_list *stack);

#endif