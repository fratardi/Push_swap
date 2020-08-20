/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:19:03 by fratardi          #+#    #+#             */
/*   Updated: 2019/11/04 15:01:03 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/ft_printf.h"
#include "../push_swap_srcs/push_swap.h"
#include <unistd.h>
#include <stdlib.h>

unsigned char	ft_apply_move_stack(t_stack *stack, char *str)
{
	if (!ft_strcmp(str, "pa\n\0"))
		return (ft_pa(stack));
	if (!ft_strcmp(str, "pb\n\0"))
		return (ft_pb(stack));
	if (!ft_strcmp(str, "sa\n"))
		return (ft_sa(stack));
	if (!ft_strcmp(str, "sb\n"))
		return (ft_sb(stack));
	if (!ft_strcmp(str, "ss\n"))
		return (ft_ss(stack));
	if (!strcmp(str, "ra\n"))
		return (ft_ra(stack));
	if (!strcmp(str, "rb\n"))
		return (ft_rb(stack));
	if (!ft_strcmp(str, "rr\n"))
		return (ft_rr(stack));
	if (!ft_strcmp(str, "rra\n"))
		return (ft_rra(stack));
	if (!ft_strcmp(str, "rrb\n"))
		return (ft_rrb(stack));
	if (!ft_strcmp(str, "rrr\n"))
		return (ft_rrr(stack));
	return (0);
}

static int		ft_iter_moves(t_stack *stack, char *str, void *buf)
{
	unsigned char ret;

	ret = ft_apply_move_stack(stack, str);
	if (0xFF && !ret)
		return (0);
	ft_bzero(buf, 4);
	return (1);
}

int				free_stack(t_stack *stack)
{
	free(stack->mem);
	free(stack->pivots);
	return (0);
}

int				read_check(t_stack *stack, size_t *n)
{
	void	*buf;
	char	str[5];

	buf = NULL;
	while (3 >= (*n = read(0, &buf, 3)))
	{
		ft_bzero(str, 5);
		ft_strcpy(str, (char *)&buf);
		if (*n == 3 && str[*n - 1] != '\n')
		{
			if (!(*n = read(0, &buf, 1)))
				return (!(int)write(2, "Error\n", 6) && free_stack(stack));
			str[3] = *(char *)&buf;
		}
		if (!ft_iter_moves(stack, str, &buf))
			break ;
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_stack		stack;
	size_t		n;

	n = 0;
	if (argc < 2)
		return (0);
	if (!fill_zone(argv, &stack) || ft_doobloons(&stack))
		return (!(int)write(2, "Error\n", 6));
	stack.debug = ((stack.debug > 0) ? 3 : 4);
	if (stack.a_len > 0)
		if (!(read_check(&stack, &n)))
			return (0);
	if (n <= 0 && ft_area_sorted_a(&stack) && !stack.b_len)
		return (!ft_printf("OK\n", free_stack(&stack)));
	free_stack(&stack);
	return ((n == 0) ? ft_printf("KO\n") : !(int)write(2, "Error\n", 6));
}
