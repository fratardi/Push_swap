/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pivots.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:26:27 by fratardi          #+#    #+#             */
/*   Updated: 2019/10/30 03:26:37 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks if top elems of the stack are not considered as pivot s
*/

int		ft_is_start_piv(t_stack *stack)
{
	if (is_pivot(stack, A_START) || is_pivot(stack, A_START_NEXT) ||
		is_pivot(stack, B_START_NEXT) || is_pivot(stack, B_START))
		return (1);
	return (0);
}

/*
** gets the last pivot of the list of pivots
*/

int		get_upper_pivot(t_stack *stack)
{
	t_pivot *pivot;

	pivot = stack->pivots;
	while (pivot->next != NULL)
		pivot = pivot->next;
	return (pivot->nb);
}

/*
**	Adds a new pivot just before last pivot on stack B  at the end of pivot list
*/

int		ft_edit_last_pivot(t_stack *stack)
{
	t_pivot	*pivot;

	pivot = stack->pivots;
	while (pivot->next->next != NULL)
		pivot = pivot->next;
	pivot->next->nb = stack->mem[B_START_POS + pivot->size];
	return (1);
}

/*
** Check if value sent as parameter is a pivot
*/

int		is_pivot(t_stack *stack, int pivot)
{
	t_pivot *list;

	list = stack->pivots;
	while (list->next)
	{
		if (list->nb == pivot)
			return (1);
		list = list->next;
	}
	if (list->nb == pivot)
		return (1);
	return (0);
}

/*
** Counts the number of pivots on stack B
*/

int		howmany_piv_b(t_stack *stack)
{
	unsigned int	i;
	int				count;

	i = B_START_POS;
	count = 0;
	while (i < M_LEN)
	{
		if (is_pivot(stack, stack->mem[i]))
			count++;
		i++;
	}
	return (count);
}
