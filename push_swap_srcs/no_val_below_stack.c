/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_val_below_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:23:21 by fratardi          #+#    #+#             */
/*   Updated: 2019/10/30 03:23:24 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_no_val_below_stack_a(t_stack *stack)
{
	unsigned int i;

	i = 0;
	while (i <= A_LEN - 1)
	{
		if (stack->mem[i] < B_END)
			return (1);
		i++;
	}
	return (0);
}

char	ft_no_val_below_stack_b(t_stack *stack)
{
	unsigned int i;

	i = B_START_POS;
	while (i <= M_LEN - 1)
	{
		if (stack->mem[i] < A_END)
			return (1);
		i++;
	}
	return (0);
}
