/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 13:09:59 by avuorio       #+#    #+#                 */
/*   Updated: 2021/09/15 13:39:56 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_data(char *str, int data)
{
	printf("%s %i\n", str, data);
}

void	print_banner(void)
{
	printf("\n");
	printf("\033[38;5;167m ███████╗████████╗ █████╗  ██████╗██╗  ██╗    ███████╗ ██████╗ ██████╗ ████████╗███████╗██████╗ ██╗ \033[m\n");
	printf("\033[38;5;168m ██╔════╝╚══██╔══╝██╔══██╗██╔════╝██║ ██╔╝    ██╔════╝██╔═══██╗██╔══██╗╚══██╔══╝██╔════╝██╔══██╗██║ \033[m\n");
	printf("\033[38;5;169m ███████╗   ██║   ███████║██║     █████╔╝     ███████╗██║   ██║██████╔╝   ██║   █████╗  ██║  ██║██║ \033[m\n");
	printf("\033[38;5;170m ╚════██║   ██║   ██╔══██║██║     ██╔═██╗     ╚════██║██║   ██║██╔══██╗   ██║   ██╔══╝  ██║  ██║╚═╝ \033[m\n");
	printf("\033[38;5;171m ███████║   ██║   ██║  ██║╚██████╗██║  ██╗    ███████║╚██████╔╝██║  ██║   ██║   ███████╗██████╔╝██╗ \033[m\n");
	printf("\033[38;5;171m ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═════╝ ╚═╝ \033[m\n");
}

void	print_stack(t_list *list, char c)
{
	t_list	*temp;
	t_list	*stop;
	int		i;
	int		colour;

	if (!list)
		return ;
	i = 1;
	colour = 21;
	temp = list;
	stop = list->prev;
	printf("\n~~~~~ sorted stack ~~~~~\n");
	while (temp)
	{
		printf("\033[38;5;%im %c - %4i: %10i \033[m\n", colour, c, i, temp->data);
		if (temp == stop)
			break ;
		temp = temp->next;
		i++;
		colour++;
		if (colour > 231)
			colour = 21;
	}
}

void	print_values(t_all *all)
{
	print_data("big rotate:", all->ops->r_big);
	print_data("big reverse:", all->ops->rr_big);
	print_data("small rotate:", all->ops->r_small);
	print_data("small reverse:", all->ops->rr_small);
}
