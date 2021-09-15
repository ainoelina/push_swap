/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:44:15 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/15 13:41:14 by avuorio       ########   odam.nl         */
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
# define DUPLICATE_ARGS -2
# define MALLOC_FAIL -3

/*
** ~~~~~~~~ STACKS ~~~
*/

# define A 1
# define B 2
# define A_LAST 3
# define B_LAST 4

/*
** ~~~~~~~~ OPERATIONS ~~~
*/
# define PA 1
# define PB 2
# define RA 3
# define RB 4
# define RR 5
# define RRA 6
# define RRB 7
# define RRR 8
# define SA 9
# define SB 10
# define SS 11

/*
** ~~~~~~~~ INT VALUES ~~~
*/
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_operations
{
	int	small;
	int	big;
	int	r_small;
	int	r_big;
	int	rr_small;
	int	rr_big;
	int	tracker;
	int	counter;
}				t_operations;

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct s_all
{
	t_list			*a;
	t_list			*b;
	t_operations	*ops;
	void			*last_node;
	char			**argv;
	int				top;
	int				min;
	int				max;
	int				len;
	int				median;
	int				chunk1;
	int				chunk3;
}				t_all;

/*
** ~~~~~~~~ OPERATIONS ~~~
*/
void	push(t_all *all, int op);
void	swap(t_all *all, int stack, int op);
void	swap_ab(t_all *all);
void	rotate(t_all *all, int stack, int op);
void	rotate_ab(t_all *all);
void	reverse_rotate(t_all *all, int stack, int op);
void	reverse_rotate_ab(t_all *all);

/*
** ~~~~~~~~ SORTING ALGORITHM ~~~
*/
void	sort_stack(t_all *all);
void	sort_small(t_all *all, int len);
void	sort_medium(t_all *all, t_operations *ops);
void	define_operations(t_all *all, t_operations *ops, int stack);

void	median(t_all *all, int stack);

void	check_big(t_all *all, t_operations *ops);
void	check_small(t_all *all, t_operations *ops);

/*
** ~~~~~~~~ MODIFY STACK ~~~
*/

void	create_stack(t_all *all, int argc, char **argv);
void	insert_last(t_all *all, int stack, int data);
void	insert_top(t_all *all, int stack, int data);
void	delete_top(t_all *all, int stack);

/*
** ~~~~~~~~ CHECKS ~~~
*/
void	check_input(t_all *all);
void	check_duplicates(t_list *list, t_all *all);
void	error_handling(int error, t_all *all);
void	find_values(t_all *all, int stack);
void	find_max(t_all *all, int stack);
void	find_min(t_all *all, int stack);
void	last_node(t_all *all, int stack);

int		sorted(t_list *a);

/*
** ~~~~~~~~ UTILS ~~~
*/

void	*malloc_memory(size_t size);

int		ft_strlen(char *str);
int		my_atoi(char *str);
int		is_digit(int c);
int		stack_len(t_all *all);
int		get_position(char *str);

t_all	*init_struct(t_all *all, char **argv);

void	init_operations(t_all *all, t_operations *ops);
void	reset(t_operations *ops);

/*
** ~~~~~~~~ PRINT TOOLS (EXTRA) ~~~
*/
void	print_stack(t_list *list, char c);
void	print_address(void *p, char *str);
void	print_all(char *str, int data);
void	print_values(t_all *all);
void	print_data(char *str, int data);
void	print_banner(void);

#endif