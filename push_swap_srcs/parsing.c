/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:24:01 by fratardi          #+#    #+#             */
/*   Updated: 2019/11/04 15:00:32 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/*
**	Checks if int given as parameter is aready a value contained int the array
*/

int				is_already_define(int *zone, unsigned int size, int to_compare)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (zone[i] == to_compare)
			return (1);
		i++;
	}
	return (0);
}

/*
**	Computes the len of the array to create
*/

unsigned int	zone_size(char **av)
{
	unsigned int i;
	unsigned int y;
	unsigned int size;

	i = 1;
	size = 0;
	while (av[i])
	{
		y = 0;
		while (av[i][y])
		{
			if ((y == 0 && (ft_isdigit(av[i][y]) || ft_strchr("+-", av[i][y])))
				|| (av[i][y + 1] && av[i][y] == ' ' &&
					(ft_isdigit(av[i][y + 1]) ||
						ft_strchr("+-", av[i][y + 1]))))
				size++;
			y++;
		}
		i++;
	}
	return (size);
}

/*
**	Checks if Any Flaw is Hidden within the arguments
**	if it doesn't contains flaw add the matching values to the tab
**	else free hte tab
*/

static int		ft_check_flaws(t_zone *zone, char **av)
{
	if ((!ft_isdigit(av[zone->i][zone->y]) &&
		!ft_strchr("+- ", av[zone->i][zone->y])) ||
			(av[zone->i][zone->y] == ' ' && av[zone->i][zone->y + 1] &&
				ft_isdigit(av[zone->i][zone->y + 1]) &&
					is_already_define(zone->zone, zone->z,
						ft_atoi(&av[zone->i][zone->y]))))
	{
		free(zone->zone);
		return (0);
	}
	if ((zone->y == 0 && (ft_isdigit(av[zone->i][zone->y]) ||
		ft_strchr("+-", av[zone->i][zone->y])))
		|| (zone->y > 0 && av[zone->i][zone->y - 1] == ' ' &&
			(ft_isdigit(av[zone->i][zone->y]) ||
				ft_strchr("+-", av[zone->i][zone->y]))))
	{
		if (!(0xFFFFFFFF00000000 & ft_overflowcheck(&av[zone->i][zone->y])))
			zone->zone[zone->z++] = ft_atoi(&av[zone->i][zone->y]);
		else
		{
			free(zone->zone);
			return (0);
		}
	}
	return (1);
}

/*
**	add every value to the stack excet if it finds flaw
*/

static int		ft_iterate_args(t_zone *zone, char **av)
{
	while (av[zone->i])
	{
		zone->y = 0;
		while (av[zone->i][zone->y])
		{
			if (!ft_check_flaws(zone, av))
				return (0);
			zone->y++;
		}
		zone->i++;
	}
	return (1);
}

int				fill_zone(char **av, t_stack *stack)
{
	t_zone zone;

	zone.size = zone_size(av);
	if (zone.size == 0)
		return (0);
	zone.i = 1;
	zone.z = 0;
	ft_check_debug(av[zone.i], &zone.tmp);
	if (zone.tmp)
		zone.i++;
	if (!(zone.zone = (int *)ft_memalloc(sizeof(int) * (zone.size))))
		return (0);
	if (!ft_iterate_args(&zone, av))
		return (0);
	*stack = ft_init_stacks(zone.zone, zone.z);
	stack->debug = zone.tmp;
	return (1);
}
