/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:24:51 by fratardi          #+#    #+#             */
/*   Updated: 2019/11/02 16:07:13 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void			print_a(t_stack *stack, int sign, unsigned int pos)
{
	if (is_pivot(stack, stack->mem[pos]))
	{
		ft_printf("\033[32m|A[%-3 d][%-3 d][", pos, *(stack->mem + pos));
		if (*(stack->mem + pos) != 0)
			ft_print_preset_buf(((sign == 1) ? '+' : '-'),
				(sign == 1) ? *(stack->mem + pos) : -*(stack->mem + pos));
		if (*(stack->mem + pos) == 0)
			ft_printf("0");
		ft_printf("%-* s]\033[00m", 102 - ((sign == 1) ?
			*(stack->mem + pos) : -*(stack->mem + pos)), " ");
	}
	else
	{
		ft_printf("\033[96m|A[%-3 d][%-3 d][", pos, *(stack->mem + pos));
		if (*(stack->mem + pos) != 0)
			ft_print_preset_buf(((sign == 1) ? '+' : '-'),
				(sign == 1) ? *(stack->mem + pos) : -*(stack->mem + pos));
		if (*(stack->mem + pos) == 0)
			ft_printf("0");
		ft_printf("%-* s]\033[00m", 102 - ((sign == 1) ?
			*(stack->mem + pos) : -*(stack->mem + pos)), " ");
	}
}

static void		ft_print_rest_b(t_stack *stack, int sign, int pos)
{
	ft_printf("\033[96m|B[%-3 d][%-3 d][",
		pos, *(stack->mem + pos + A_LEN));
	if (*(stack->mem + pos + A_LEN) != 0)
		ft_print_preset_buf(((sign == 1) ? '+' : '-'), (sign == 1) ?
			*(stack->mem + pos + A_LEN) : -*(stack->mem + pos + A_LEN));
	if (*(stack->mem + pos + A_LEN) == 0)
		ft_printf("0");
	if (*(stack->mem + pos + A_LEN) >= 0)
		ft_printf("%-* s]\033[00m", 102 - *(stack->mem + pos + A_LEN), " ");
	else
		ft_printf("%-* s]\033[00m", 102 + *(stack->mem + pos + A_LEN), " ");
}

void			print_b(t_stack *stack, int sign, int pos)
{
	if (is_pivot(stack, *(stack->mem + pos + A_LEN)))
	{
		ft_printf("\033[32m|B[%-3 d][%-3 d][", pos,
			*(stack->mem + pos + A_LEN));
		if (*(stack->mem + pos + A_LEN) != 0)
			ft_print_preset_buf(((sign == 1) ? '+' : '-'), (sign == 1) ?
				*(stack->mem + pos + A_LEN) : -*(stack->mem + pos + A_LEN));
		if (*(stack->mem + pos + A_LEN) == 0)
			ft_printf("0");
		if (*(stack->mem + pos + A_LEN) >= 0)
			ft_printf("%-* s]\033[00m", 102 - *(stack->mem + pos + A_LEN), " ");
		else
			ft_printf("%-* s]\033[00m", 102 + *(stack->mem + pos + A_LEN), " ");
	}
	else
		ft_print_rest_b(stack, sign, pos);
}

static void		ft_get_wait(t_stack *stack)
{
	if (stack->debug == 2)
		getchar();
	if (stack->debug == 1 && (B_LEN || !ft_area_sorted_a(stack)))
	{
		usleep(100000);
		ft_print_preset_buf('\n', 300);
	}
}

void			print_stack_content(t_stack *stack)
{
	unsigned int	pos;
	int				sign;

	pos = 0;
	ft_printf("moves :=[%d]\n", stack->moves);
	while (pos < stack->memlen)
	{
		if (A_LEN && pos < stack->a_len)
		{
			sign = (*(stack->mem + pos) >= 0) ? 1 : -1;
			print_a(stack, sign, pos);
		}
		if (pos + A_LEN < (A_LEN + B_LEN))
		{
			if (pos >= A_LEN)
				ft_printf("|A[   ][   ][%-102 s]", " ", " ");
			sign = (*(stack->mem + pos + A_LEN) >= 0) ? 1 : -1;
			print_b(stack, sign, pos);
		}
		ft_putchar('\n');
		pos++;
	}
	ft_printf("=====================\n");
	ft_get_wait(stack);
}
