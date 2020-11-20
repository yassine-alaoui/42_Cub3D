/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:32:53 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/11/20 11:51:44 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int i;

	i = 0;
	if (n)
	{
		while (i < n)
		{
			*(unsigned char*)s = 0;
			s++;
			i++;
		}
	}
}

void	ft_drawasquare(int a, int b, t_mapdata *map)
{
	int			i;
	int			j;

	i = 0;
	while (i <= 7)
	{
		j = 0;
		while (j <= 7)
		{
			DATA[(j + b) * WH + (i + a)] = 0x0fffff;
			j++;
		}
		i++;
	}
}

void	ft_drawaplayer(t_mapdata *map)
{
	double			theone;
	int				i;
	t_horizontal	*it;
	t_horizontal	*tmp;

	tmp = 0;
	it = 0;
	tmp = it;
	it = malloc(sizeof(t_horizontal));
	init(it);
	i = 0;
	ft_lstadd_front(&g_mylist, ft_lstnew(it));
	ARC = ANGLE - (M_PI / 6);
	while (i < WH)
	{
		if (ARC < 0)
			ARC += 2 * M_PI;
		if (ARC > M_PI * 2)
			ARC -= (M_PI * 2);
		theone = colmdist(map, it);
		RAYDIST[i] = theone;
		generete_wall(map, it, i, theone);
		ARC += (M_PI / 3) / WH;
		i++;
	}
	free(tmp);
	to_sprite(map, -1);
}
