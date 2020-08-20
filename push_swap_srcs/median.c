/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:22:57 by fratardi          #+#    #+#             */
/*   Updated: 2019/10/30 03:23:00 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			search_pos(t_stack *stack, t_med *med)
{
	if (med->ret < 0)
		med->ret = -med->ret;
	med->low = med->tmp - stack->mem[med->i];
	if ((med->tmp - stack->mem[med->i] < med->ret))
	{
		if (med->low <= 0 && -med->low < med->ret)
		{
			med->ret = -med->low;
			med->pos = med->i;
		}
		else if (med->low > 0)
		{
			med->ret = med->low;
			med->pos = med->i;
		}
	}
	med->i++;
}

unsigned int	pos_precise_med_a(t_stack *stack)
{
	t_med med;

	med.i = 0;
	med.low = (stack->mem[med.i]);
	while (med.i < A_LEN)
	{
		if (stack->mem[med.i] < med.low)
			med.low = stack->mem[med.i];
		med.i++;
	}
	med.i = 0;
	med.high = stack->mem[med.i];
	while (med.i < A_LEN)
	{
		if (stack->mem[med.i] > med.high)
			med.high = stack->mem[med.i];
		med.i++;
	}
	med.tmp = ((med.high - med.low) / 2) + med.low;
	med.i = 0;
	med.ret = med.high;
	while (med.i < A_LEN)
		search_pos(stack, &med);
	return (med.pos);
}

unsigned int	pos_precise_med_b(t_stack *stack)
{
	t_med med;

	med.i = B_START_POS;
	med.low = (stack->mem[med.i]);
	while (med.i < M_LEN)
	{
		if (stack->mem[med.i] < med.low)
			med.low = stack->mem[med.i];
		med.i++;
	}
	med.i = B_START_POS;
	med.high = stack->mem[med.i];
	while (med.i < M_LEN)
	{
		if (stack->mem[med.i] > med.high)
			med.high = stack->mem[med.i];
		med.i++;
	}
	med.tmp = ((med.high - med.low) / 2) + med.low;
	med.i = B_START_POS;
	med.ret = med.high;
	while (med.i < M_LEN)
		search_pos(stack, &med);
	return (med.pos);
}
