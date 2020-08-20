/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:00:09 by fratardi          #+#    #+#             */
/*   Updated: 2019/11/04 15:00:12 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		c_fold_iter(t_stack *stack, unsigned int *pushed,
	unsigned int pos)
{
	ft_add_pivot(stack, M_LEN - pos);
	while (pos-- && B_LEN && howmany_piv_b(stack) > 0)
	{
		ft_rrb(stack);
		if (M_LEN - pos != M_LEN && B_START > stack->mem[M_LEN - pos])
		{
			ft_pa(stack);
			*pushed += 1;
		}
	}
}

/*
**	values higher than pivot will go on the top of a the other goes to top of b
*/

void			ft_c_fold(t_stack *stack, unsigned int *pushed,
	unsigned int pos)
{
	if (pos && howmany_piv_b(stack) > 1)
		ft_pa(stack);
	if (is_pivot(stack, A_START) && is_pivot(stack, B_START) && pos)
		c_fold_iter(stack, pushed, pos);
	else
	{
		while (pos-- && B_LEN && howmany_piv_b(stack) > 1)
			ft_rrb(stack);
	}
	if (!is_pivot(stack, A_START) && !is_pivot(stack, A_START_NEXT) &&
		A_START > A_START_NEXT)
		ft_sa(stack);
}

/*
**	values higher than pivot will go on a the rest goes bottom rest
*/

static void		b_fold_rest(t_stack *stack, unsigned int size,
	unsigned int *pos, unsigned int *push)
{
	t_pivot			*pivot;

	pivot = stack->pivots;
	while (pivot->next)
		pivot = pivot->next;
	if (size != 0 && B_LEN > 1 && howmany_piv_b(stack) == 1)
	{
		ft_pa(stack);
		ft_ra(stack);
		while (size)
		{
			if (size-- && B_START > pivot->nb)
			{
				ft_pa(stack);
				*push += 1;
			}
			else if (*pos += 1)
				ft_rb(stack);
		}
		ft_rra(stack);
	}
	else if (B_LEN == 1)
		ft_pa(stack);
}

/*
**	values higher than pivot will go on a the rest goes bottom
*/

void			ft_b_fold(t_stack *stack, unsigned int *push, unsigned int *pos)
{
	t_pivot			*pivot;
	unsigned int	size;

	pivot = stack->pivots;
	size = B_LEN;
	while (pivot->next)
		pivot = pivot->next;
	while (B_START != pivot->nb && (size = B_LEN) > 1)
	{
		if (B_START > pivot->nb)
		{
			ft_pa(stack);
			*push += 1;
		}
		else
		{
			ft_rb(stack);
			*pos += 1;
		}
		size--;
	}
	b_fold_rest(stack, size, pos, push);
}

/*
**	lanch procedures off sorts accrding too it's conditions
*/

void			unfold_start(t_stack *stack)
{
	t_fold fold;

	while (B_LEN && is_pivot(stack, B_START))
		ft_pa(stack);
	if (B_LEN <= 17 && !ft_area_sorted_b(stack) && howmany_piv_b(stack) == 0)
		return (ft_recu(stack));
	else if (howmany_piv_b(stack) == 0 && B_LEN > 3)
		ft_add_pivot(stack, pos_precise_med_b(stack));
	else
		ft_add_pivot(stack, B_START_POS + pso_on_b(stack) - 1);
	fold.pushed_size = 0;
	fold.stack_l = 0;
	ft_b_fold(stack, &fold.pushed_size, &fold.stack_l);
	if (fold.pushed_size <= 2)
		if (!is_pivot(stack, A_START) && !is_pivot(stack, A_START_NEXT) &&
			A_START > A_START_NEXT)
			ft_sa(stack);
	if (B_LEN)
		ft_c_fold(stack, &fold.pushed_size, fold.stack_l);
	if (fold.pushed_size > 2 && !ft_area_sorted_a(stack))
		ft_a_fold(stack, fold.pushed_size);
	else if (B_LEN > 1)
		unfold_start(stack);
}
