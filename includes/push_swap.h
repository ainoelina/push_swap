/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:44:15 by avuorio       #+#    #+#                 */
/*   Updated: 2021/08/25 16:28:17 by avuorio       ########   odam.nl         */
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
# define UNUsed ERROR -2
# define DUPLICATE_ARGS -3
# define MALLOC_FAIL -4

/*
** ~~~~~~~~ STACKS ~~~
*/

# define A 1
# define B 2

/*
** ~~~~~~~~ INT VALUES ~~~
*/
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_operations
{
	int	small;
	int	big;
	int	rotate_small;
	int	rotate_big;
	int	reverse_small;
	int	reverse_big;
}				t_operations;

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct s_data
{
	t_list			*a;
	t_list			*b;
	t_operations	*ops;
	char			**argv;
	int				top;
	int				min;
	int				max;
	int				len;
	int				median;
}				t_data;

/*
** ~~~~~~~~ OPERATIONS ~~~
*/
void	push(t_list **dest, t_list **src, t_data *all);
void	swap(t_data *all, int stack);
void	swap_ab(t_data *all);
void	rotate(t_data *all, int stack);
void	rotate_ab(t_data *all);
void	reverse_rotate(t_list **stack);
void	reverse_rotate_ab(t_data *all);
void	rotate_a(t_list **a);

/*
** ~~~~~~~~ SORTING ALGORITHM ~~~
*/
void	sort_stack(t_data *all);
void	sort_small(t_data *all, int len);
void	sort_medium(t_data *all);
void	define_operations(t_data *all, int stack);

void	median(t_data *all, int stack);

/*
** ~~~~~~~~ MODIFY STACK ~~~
*/

void	create_stack(t_data *all, int argc, char **argv);
void	insert_last(t_data *all, int stack, int data);
void	insert_top(t_data *all, int stack, int data);
void	delete_top(t_data *all, int stack);

/*
** ~~~~~~~~ CHECKS ~~~
*/
void	check_input(t_data *all);
void	check_duplicates(t_list *list);
void	error_handling(int error);
void	find_values(t_data *all, int stack);
void	find_max(t_data *all, int stack);
void	find_min(t_data *all, int stack);

int		sorted(t_list *a);

t_list	*last_node(t_list *list);

/*
** ~~~~~~~~ UTILS ~~~
*/

void	*malloc_memory(size_t size);

int		ft_strlen(char *str);
int		my_atoi(char *str);
int		is_digit(int c);
int		stack_len(t_list *stack);
int		get_position(char *str);

void	init_struct(t_data *all, char **argv);

/*
** ~~~~~~~~ PRINT TOOLS (EXTRA) ~~~
*/
void	print_stack(t_list *list);
void	print_address(void *p, char *str);
void	print_data(char *str, int data);

#endif