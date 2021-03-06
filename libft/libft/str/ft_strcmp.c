/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 23:02:34 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/22 20:27:53 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int i;

	i = 0;
	while (*(unsigned char*)(s1 + i) || *(unsigned char *)(s2 + i))
	{
		if (*(unsigned char*)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char*)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
