/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:21:41 by fratardi          #+#    #+#             */
/*   Updated: 2019/10/30 04:12:46 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**values lower than pivot will go on
**the top of b the other goes to top of a
*/

unsigned int	ft_d_fold(t_stack *stack, unsigned int stack_d)
{
	unsigned int	pushed_size;
	int				new_piv;
	unsigned int	tmp;

	pushed_size = 0;
	tmp = stack_d;
	if (stack_d > 1)
	{
		new_piv = stack->mem[A_LEN - stack_d];
		ft_add_pivot(stack, A_LEN - stack_d);
		while (tmp--)
		{
			ft_rra(stack);
			(stack->mem[0] < new_piv) ? ft_pb(stack) : pushed_size++;
		}
	}
	else
		while (tmp--)
		{
			ft_rra(stack);
			if ((!ft_is_start_piv(stack)) && A_START > A_START_NEXT)
				ft_sa(stack);
		}
	return (pushed_size);
}

/*
**values lower than pivot will go on
**the top of b the other goes to bottom of a
*/

void			ft_a_fold(t_stack *stack, unsigned int pushed)
{
	t_fold fold;

	fold.new_piv = stack->mem[pushed];
	ft_add_pivot(stack, pushed);
	if (pushed > 2 && is_stack_d_null(stack, fold.new_piv, pushed))
		ft_a_fold(stack, pushed - 1);
	fold.pushed_size = 0;
	fold.stack_l = 0;
	while (pushed && B_LEN)
	{
		if (stack->mem[0] < fold.new_piv && (fold.pushed_size += 1))
			ft_pb(stack);
		else
		{
			ft_ra(stack);
			fold.stack_l++;
		}
		pushed--;
	}
	(fold.stack_l != 0) ? ft_pb(stack) : 0;
	fold.pushed_size = ft_d_fold(stack, fold.stack_l);
	if (fold.pushed_size > 1)
		ft_a_fold(stack, fold.pushed_size);
	else if (B_LEN)
		ft_unstackifier(stack);
}
