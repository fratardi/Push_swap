/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:22:25 by fratardi          #+#    #+#             */
/*   Updated: 2019/10/30 03:22:30 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** check if area sorted on b stack lowest val up hih val down
*/

int			ft_area_sorted_a(t_stack *stack)
{
	unsigned int i;

	i = 0;
	while (i + 1 < B_START_POS)
	{
		if (stack->mem[i] > stack->mem[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/*
** check if area sorted on b stack lowest val up hih val down
*/

int			ft_area_sorted_b(t_stack *stack)
{
	unsigned int i;

	i = B_START_POS;
	while (i + 1 < M_LEN)
	{
		if (stack->mem[i] < stack->mem[i + 1])
			return (0);
		i++;
	}
	return (1);
}
