/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:25:20 by fratardi          #+#    #+#             */
/*   Updated: 2019/10/30 03:25:22 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

unsigned char	ft_ra(t_stack *stack)
{
	if (A_LEN > 1)
	{
		rot_up(&stack->mem[0], A_LEN);
		if (stack->debug < 3)
			write(1, "ra\n", 3);
		MOVES++;
		if (stack->debug > 0 && stack->debug < 4)
			print_stack_content(stack);
		return (RA);
	}
	return (ERR_A | RA);
}

unsigned char	ft_rb(t_stack *stack)
{
	if (B_LEN > 1)
	{
		rot_up(&stack->mem[A_LEN], B_LEN);
		if (stack->debug < 3)
			write(1, "rb\n", 3);
		MOVES++;
		if (stack->debug > 0 && stack->debug < 4)
			print_stack_content(stack);
		return (RB);
	}
	return (ERR_B | RB);
}

unsigned char	ft_rr(t_stack *stack)
{
	unsigned int	debcpy;
	unsigned char	ret1;
	unsigned char	ret2;

	debcpy = stack->debug;
	stack->debug = 4;
	ret1 = ft_ra(stack);
	ret2 = ft_rb(stack);
	if (stack->debug < 3)
		write(1, "rr\n", 3);
	stack->debug = debcpy;
	if (stack->debug > 0 && stack->debug < 4)
		print_stack_content(stack);
	MOVES--;
	return (ret1 | ret2);
}
