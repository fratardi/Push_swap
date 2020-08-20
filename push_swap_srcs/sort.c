/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:26:11 by fratardi          #+#    #+#             */
/*   Updated: 2019/11/04 15:00:54 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_unstackifier(t_stack *stack)
{
	if (B_LEN && is_pivot(stack, B_START) && !ft_area_sorted_b(stack))
	{
		ft_pa(stack);
		ft_unstackifier(stack);
	}
	else if (B_LEN)
		unfold_start(stack);
}

/*
** sort the three last elems of stack a after the stackifier
*/

void	ft_sort_three_a(t_stack *stack)
{
	if (A_LEN == 3)
	{
		while (!ft_area_sorted_a(stack))
		{
			if (stack->mem[2] < A_START && A_START_NEXT > A_START)
				ft_rra(stack);
			else if (stack->mem[2] < A_START)
				ft_ra(stack);
			else if (A_START > A_START_NEXT)
				ft_sa(stack);
			if (A_START < A_START_NEXT
				&& A_START_NEXT > stack->mem[2])
			{
				ft_rra(stack);
				ft_sa(stack);
			}
		}
	}
	ft_unstackifier(stack);
}

int		ft_stackify_before_piv(t_stack *stack, unsigned int pivot_pos)
{
	unsigned int rest_to_comp;
	unsigned int i;

	rest_to_comp = 0;
	while (!is_pivot(stack, A_START))
	{
		if (A_START < stack->mem[pivot_pos])
			ft_pb(stack);
		else
		{
			ft_ra(stack);
			rest_to_comp++;
		}
		pivot_pos--;
	}
	i = A_LEN - rest_to_comp;
	return (i);
}

void	ft_stackify_after_piv(t_stack *stack, unsigned int i)
{
	while (i && A_LEN && ft_no_val_below_stack_a(stack))
	{
		if (B_END > A_START)
			ft_pb(stack);
		else
			ft_ra(stack);
		i--;
	}
	ft_rrb(stack);
}

void	ft_stackifyfrom(t_stack *stack)
{
	unsigned int pivot_pos;
	unsigned int i;

	if (A_LEN <= 3)
	{
		ft_sort_three_a(stack);
		return ;
	}
	if (A_LEN > 5)
		pivot_pos = pos_precise_med_a(stack);
	else
		pivot_pos = A_LEN - 1;
	ft_add_pivot(stack, pivot_pos);
	i = ft_stackify_before_piv(stack, pivot_pos);
	if (i)
	{
		ft_pb(stack);
		ft_rb(stack);
	}
	ft_stackify_after_piv(stack, i);
	if (A_LEN >= 3 && B_LEN)
		ft_stackifyfrom(stack);
	else if (A_LEN)
		if (A_LEN == 2 && A_START > A_START_NEXT)
			ft_sa(stack);
}
