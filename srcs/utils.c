/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 11:07:03 by avuorio       #+#    #+#                 */
/*   Updated: 2021/05/27 13:29:46 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pointer;
	size_t			i;

	i = 0;
	pointer = (unsigned char *)b;
	while (i < len)
	{
		pointer[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*malloc_memory(size_t size)
{
	void	*mem;

	mem = (void *)malloc(size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
