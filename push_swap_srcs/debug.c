/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:59:56 by fratardi          #+#    #+#             */
/*   Updated: 2019/11/04 15:00:00 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void			ft_check_debug(char *str, unsigned int *debug)
{
	if (!ft_strcmp("-v", str))
		*debug = 1;
	else if (!ft_strcmp("-d", str))
		*debug = 2;
	else
		*debug = 0;
}

/*
**	check for overflows or extra errors
*/

unsigned long	ft_overflowcheck(char *str)
{
	long	ret;
	char	sig;
	long	i;

	i = 0;
	ret = 0x000000000000;
	sig = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -sig;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0xFFFFFFFF00000000);
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ((ret * 10) + (str[i++] - '0'));
		if ((ret > 2147483647 && sig > 0) || (ret > 2147483648))
			return (0xFFFFFFFF00000000);
	}
	return ((str[i] && str[i] != ' ') ? 0xFFFFFFFF00000000 : (ret));
}

unsigned char	ft_doobloons(t_stack *stack)
{
	unsigned int i;
	unsigned int j;

	j = 0;
	if (!A_LEN)
		return (!free_stack(stack));
	while (j < A_LEN - 1)
	{
		i = j + 1;
		while (i <= A_LEN - 1)
		{
			if (stack->mem[i] == stack->mem[j])
				return (!free_stack(stack));
			i++;
		}
		j++;
	}
	return (0);
}

/*
**	initiate stacks
*/

t_stack			ft_init_stacks(int *mem, unsigned int tablen)
{
	t_stack stack;

	stack.mem = mem;
	stack.memlen = tablen;
	stack.a_len = tablen;
	stack.b_len = 0;
	stack.moves = 0;
	stack.pivots = (t_pivot *)malloc(sizeof(t_pivot));
	stack.pivots->next = NULL;
	stack.pivots->size = 0;
	stack.debug = 2;
	return (stack);
}
