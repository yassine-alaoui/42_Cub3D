/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildwall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:26:44 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/16 17:32:16 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

static int	color(t_horizontal *it)
{
	if (FCEUP && HH)
		return (0x4932fa);
	else if (FCELEFT && HV)
		return (0x25faa6);
	else if (FCEDOWN && HH)
		return (0xfaeA57);
	else if (FCERIGHT && HV)
		return (0xfa4925);
	return (0);
}

static void	render_wall(t_mapdata *map, double stripheight,
	int b, t_horizontal *it)
{
	int			i;
	int			wall;

	wall = (int)stripheight;
	i = (HT / 2) - (wall / 2);
	while (i < (HT / 2) + (wall / 2))
	{
		if (i >= 0 && i < HT && b >= 0 && b < WH)
			DATA[i * WH + b] = color(it);
		i++;
	}
}

void		generete_wall(t_mapdata *map, t_horizontal *it, int b)
{
	double		prjplane;
	double		dist;
	double		stripheight;

	dist = colmdist(map, it) * cos(ARC - ANGLE);
	prjplane = (WH / 2) / tan(M_PI / 6);
	stripheight = (32 / dist) * prjplane;
	render_wall(map, stripheight, b, it);
}
