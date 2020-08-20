/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:25:59 by fratardi          #+#    #+#             */
/*   Updated: 2019/10/30 03:26:03 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

unsigned char	ft_sa(t_stack *stack)
{
	if (A_LEN > 1)
	{
		ft_swap(&(stack->mem[START_A]), &(stack->mem[START_A + 1]));
		if (stack->debug < 3)
			write(1, "sa\n", 3);
		MOVES++;
		if (stack->debug > 0 && stack->debug < 4)
			print_stack_content(stack);
		return (SA);
	}
	return (ERR_A | SA);
}

unsigned char	ft_sb(t_stack *stack)
{
	if (B_LEN > 1)
	{
		ft_swap(&(stack->mem[A_LEN]), &(stack->mem[A_LEN + 1]));
		if (stack->debug < 3)
			write(1, "sb\n", 3);
		MOVES++;
		if (stack->debug > 0 && stack->debug < 4)
			print_stack_content(stack);
		return (SB);
	}
	return (ERR_B | SB);
}

unsigned char	ft_ss(t_stack *stack)
{
	unsigned int	debcpy;
	unsigned char	ret1;
	unsigned char	ret2;

	debcpy = stack->debug;
	stack->debug = 4;
	ret1 = ft_sa(stack);
	ret2 = ft_sb(stack);
	if (stack->debug < 3)
		write(1, "ss\n", 3);
	stack->debug = debcpy;
	if (stack->debug > 0 && stack->debug < 4)
		print_stack_content(stack);
	MOVES--;
	return (ret1 | ret2);
}
