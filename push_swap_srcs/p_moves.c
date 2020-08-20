/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:23:38 by fratardi          #+#    #+#             */
/*   Updated: 2019/10/30 03:23:48 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

unsigned char	ft_pb(t_stack *stack)
{
	if (A_LEN)
	{
		rot_up(stack->mem, A_LEN);
		A_LEN--;
		B_LEN++;
		if (stack->debug < 3)
			write(1, "pb\n", 3);
		MOVES++;
		if (stack->debug > 0 && stack->debug < 4)
			print_stack_content(stack);
		return (PB);
	}
	return (ERR_B | PB);
}

unsigned char	ft_pa(t_stack *stack)
{
	if (stack->b_len >= 1)
	{
		rot_down(stack->mem, A_LEN + 1);
		A_LEN++;
		B_LEN--;
		if (stack->debug < 3)
			write(1, "pa\n", 3);
		MOVES++;
		if (stack->debug > 0 && stack->debug < 4)
			print_stack_content(stack);
		return (PA);
	}
	return (ERR_A | PA);
}
