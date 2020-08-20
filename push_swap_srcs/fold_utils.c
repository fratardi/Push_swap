/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:22:09 by fratardi          #+#    #+#             */
/*   Updated: 2019/10/30 03:22:13 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_list_pivots(t_stack *stack)
{
	t_pivot	*list;

	list = stack->pivots;
	while (list->next)
	{
		ft_printf("PIVOTS = %d\n", (int)list->nb);
		ft_printf("PIVOTS_SIZE = %d\n", (int)list->size);
		list = list->next;
	}
	ft_printf("PIVOTS = %d\n", (int)list->nb);
	ft_printf("PIVOTS_SIZE = %d\n", (int)list->size);
}

/*
** Computes the len till next  piv on stack  b
*/

unsigned int	pso_on_b(t_stack *stack)
{
	unsigned int i;

	i = 0;
	while (B_LEN > 1 && i < B_LEN &&
		!is_pivot(stack, stack->mem[B_START_POS + i]))
		i++;
	return (i);
}

int				is_stack_d_null(t_stack *stack, int new_piv, unsigned int left)
{
	unsigned int i;

	i = 0;
	while (i < left)
	{
		if (stack->mem[i] > new_piv)
			return (0);
		i++;
	}
	return (1);
}
