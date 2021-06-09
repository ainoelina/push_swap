/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:44:15 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/09 09:26:29 by avuorio       ########   odam.nl         */
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

/*
** ~~~~~~~~ DEFINES ~~~
*/

# define A 1
# define B 2


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
	int		small;
	int		big;
}				t_stack;

/*
** ~~~~~~~~ OPERATIONS ~~~
*/
void	swap(t_list **dll);
void	push(t_list **dst, t_list **src);
void	rotate(t_list **head, t_list **tail);
void	reverse_rotate(t_list **head, t_list **tail);

/*
** ~~~~~~~~ SORTING ALGORITHM ~~~
*/

void	sort_five(t_stack *a, t_stack *b, int stacklen);

void	find_values(t_stack *a, t_stack *b, int stack);
void	solve(t_stack *a, t_stack *b);

void	add_to_stack(t_stack *a, t_list *node, char *str);

void	check_duplicates(t_list *head);

void	error_handling(int error);

/*
** ~~~~~~~~ UTILS ~~~
*/

void	*malloc_memory(size_t size);

int		sorted(t_stack *a);
int		ft_strlen(char *str);
int		my_atoi(char *str);
int		is_digit(int c);
int		stack_len(t_list *stack);

#endif