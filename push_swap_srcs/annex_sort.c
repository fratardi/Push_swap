/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:20:06 by fratardi          #+#    #+#             */
/*   Updated: 2019/11/02 15:26:07 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	gives the distace to the highest value of the tab
*/

int				find_next(t_stack *stack)
{
	unsigned int	i;
	int				tmp;
	int				pos;

	i = B_START_POS;
	tmp = B_START;
	pos = B_START_POS;
	while (i < M_LEN)
	{
		if (stack->mem[i] > tmp)
		{
			tmp = stack->mem[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

/*
**	Insertion sort procedure emptying the stack B
*/

void			ft_recu(t_stack *stack)
{
	unsigned int	pivot_pos;

	pivot_pos = find_next(stack);
	ft_add_pivot(stack, pivot_pos);
	while (!is_pivot(stack, B_START))
	{
		if (pivot_pos < A_LEN + B_LEN / 2)
		{
			ft_rb(stack);
			pivot_pos--;
		}
		else
			ft_rrb(stack);
		if (B_START < B_START_NEXT)
			ft_sb(stack);
	}
	ft_pa(stack);
	if (B_LEN)
		ft_recu(stack);
}

int				ft_biggest(t_stack *stack)
{
	int				i;
	unsigned int	j;

	i = -2147483647;
	j = 0;
	while (j < A_LEN)
	{
		if (stack->mem[j] > i)
			i = stack->mem[j];
		j++;
	}
	return (i);
}

static void		ft_pull_back(t_stack *stack)
{
	while (B_LEN)
	{
		ft_pa(stack);
		if (B_LEN >= 2 && B_START < B_START_NEXT)
			ft_sb(stack);
	}
}

void			ft_sort_a(t_stack *stack)
{
	unsigned int	i;
	int				last;

	i = 0;
	last = A_END;
	while (A_START != last && A_LEN > 2)
	{
		if (A_START <= stack->pivots->nb)
			ft_pb(stack);
		if (B_LEN >= 2 && B_START < B_START_NEXT)
			ft_sb(stack);
		if (A_START > stack->pivots->nb)
			ft_ra(stack);
	}
	if (A_START <= stack->pivots->nb)
		ft_pb(stack);
	if (B_LEN >= 2 && B_START < B_START_NEXT)
		ft_sb(stack);
	if (A_LEN == 2 && A_START > A_START_NEXT)
		ft_sa(stack);
	ft_sort_three_a(stack);
	ft_pull_back(stack);
}
