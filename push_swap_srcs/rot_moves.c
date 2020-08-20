/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:25:32 by fratardi          #+#    #+#             */
/*   Updated: 2019/10/30 03:25:36 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_up(int *mem, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i++ < n - 1)
		ft_swap(&(mem[i - 1]), &mem[i]);
}

void	rot_down(int *mem, unsigned int n)
{
	while (n-- > 1)
		ft_swap(&(mem[n - 1]), &mem[n]);
}
