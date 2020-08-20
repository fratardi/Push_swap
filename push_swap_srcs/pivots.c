/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivots.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:24:16 by fratardi          #+#    #+#             */
/*   Updated: 2019/10/30 03:24:19 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		howmany_pivots_b(t_stack *stack)
{
	t_pivot			*piv;
	unsigned int	count;
	unsigned int	i;

	count = 0;
	piv = stack->pivots;
	while (piv->next)
	{
		i = B_START_POS;
		while (i < M_LEN)
		{
			if (piv->nb == stack->mem[i])
				count++;
			i++;
		}
		piv = piv->next;
	}
	return (count);
}

int		howmany_pivots_a(t_stack *stack)
{
	t_pivot			*piv;
	unsigned int	count;
	unsigned int	i;

	count = 0;
	piv = stack->pivots;
	while (piv->next)
	{
		i = 0;
		while (i < A_LEN)
		{
			if (piv->nb == stack->mem[i])
				count++;
			i++;
		}
		piv = piv->next;
	}
	return (count);
}

void	size_pivot(t_stack *stack)
{
	t_pivot *piv;

	piv = stack->pivots;
	while (piv->next)
		piv = piv->next;
	piv->size++;
}

int		ft_add_pivot(t_stack *stack, unsigned int pivot_pos)
{
	t_pivot	*current;

	current = stack->pivots;
	while (current->next != NULL)
		current = current->next;
	if (current->nb != stack->mem[pivot_pos])
	{
		if (!(current->next = (t_pivot*)ft_memalloc(sizeof(t_pivot))))
			return (0);
		current = current->next;
		current->next = NULL;
		current->nb = stack->mem[pivot_pos];
		current->size = 0;
	}
	return (1);
}

int		ft_add_pivot_unfold(t_stack *stack, unsigned int pivot_pos)
{
	t_pivot	*current;

	current = stack->pivots;
	while (current->next != NULL)
		current = current->next;
	if (current->nb != stack->mem[A_LEN + pivot_pos])
	{
		if (!(current->next = (t_pivot*)ft_memalloc(sizeof(t_pivot))))
			return (0);
		current = current->next;
		current->next = NULL;
		current->nb = stack->mem[A_LEN + pivot_pos];
		current->size = 0;
	}
	return (1);
}
