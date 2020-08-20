/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:25:47 by fratardi          #+#    #+#             */
/*   Updated: 2019/10/30 03:25:49 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

unsigned char	ft_rra(t_stack *stack)
{
	if (A_LEN > 1)
	{
		rot_down(stack->mem, A_LEN);
		if (stack->debug < 3)
			write(1, "rra\n", 4);
		MOVES++;
		if (stack->debug > 0 && stack->debug < 4)
			print_stack_content(stack);
		return (RRA);
	}
	return (ERR_A | RRA);
}

unsigned char	ft_rrb(t_stack *stack)
{
	if (B_LEN > 1)
	{
		(void)rot_down(&stack->mem[A_LEN], B_LEN);
		MOVES++;
		if (stack->debug > 0 && stack->debug < 4)
			print_stack_content(stack);
		if (stack->debug < 3)
			write(1, "rrb\n", 4);
		return (RRB);
	}
	return (ERR_B | RRB);
}

unsigned char	ft_rrr(t_stack *stack)
{
	unsigned int	debcpy;
	unsigned char	ret1;
	unsigned char	ret2;

	debcpy = stack->debug;
	stack->debug = 4;
	ret1 = ft_rra(stack);
	ret2 = ft_rrb(stack);
	if (stack->debug < 3)
		ft_printf("rrr\n");
	stack->debug = debcpy;
	if (stack->debug > 0 && stack->debug < 4)
		print_stack_content(stack);
	MOVES--;
	return (ret1 | ret2);
}
