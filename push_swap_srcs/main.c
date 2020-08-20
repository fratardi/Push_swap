/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:00:20 by fratardi          #+#    #+#             */
/*   Updated: 2019/11/04 15:00:23 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_free_t_pivot(t_stack *stack)
{
	t_pivot *del;

	del = stack->pivots;
	while (stack->pivots->next)
	{
		del = stack->pivots;
		if (stack->pivots->next)
			stack->pivots = stack->pivots->next;
		free(del);
	}
	free(stack->pivots);
}

int		free_stack(t_stack *stack)
{
	free(stack->mem);
	free(stack->pivots);
	return (0);
}

int		ft_diff_sort(t_stack *stack)
{
	if (stack->a_len < 6)
	{
		(stack->a_len == 3) ? ft_sort_three_a(stack) : ft_sort_a(stack);
		return (free_stack(stack));
	}
	if (stack->mem[0] > stack->mem[1] && stack->a_len == 2)
	{
		ft_sa(stack);
		return (free_stack(stack));
	}
	if (stack->a_len == 3)
	{
		ft_sort_three_a(stack);
		return (free_stack(stack));
	}
	return (1);
}

int		main(int argc, char **argv)
{
	unsigned int	i;
	t_stack			stack;

	i = 0;
	if (argc == 1)
		return (0);
	if (argc < 2 || !fill_zone(argv, &stack) || ft_doobloons(&stack)
		|| !stack.a_len)
		return (!(int)write(2, "Error\n", 6));
	if (ft_area_sorted_a(&stack))
		return (free_stack(&stack));
	stack.pivots->nb = stack.mem[pos_precise_med_a(&stack)];
	if (!ft_diff_sort(&stack))
		return (0);
	ft_stackifyfrom(&stack);
	ft_unstackifier(&stack);
	if (stack.b_len)
		while (stack.b_len)
			ft_pa(&stack);
	free(stack.mem);
	ft_free_t_pivot(&stack);
	return (0);
}
