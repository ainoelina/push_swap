/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:44:15 by avuorio       #+#    #+#                 */
/*   Updated: 2021/06/10 11:33:24 by avuorio       ########   odam.nl         */
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
# define MALLOC_FAIL -4

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

typedef struct s_data
{
	t_list	*a;
	t_list	*b;
	char	**argv;
	int		top;
	int		argc;
	int		small;
	int		big;
}				t_data;

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

/*
** ~~~~~~~~ MODIFY STACK ~~~
*/

void	create_stack(t_data *all, int argc, char **argv);
void	add_to_tail(t_data *all, int stack, int data);
void	insert_last(t_data *all, int stack, int data);

/*
** ~~~~~~~~ CHECKS ~~~
*/
void	check_input(t_data *all);
void	check_duplicates(t_list *list);
void	error_handling(int error);

/*
** ~~~~~~~~ UTILS ~~~
*/

void	*malloc_memory(size_t size);

int		ft_strlen(char *str);
int		my_atoi(char *str);
int		is_digit(int c);
int		stack_len(t_list *stack);
int		get_position(char *str);

#endif