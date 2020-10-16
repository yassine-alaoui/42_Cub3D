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

// static int	color(t_horizontal *it)
// {
// 	if (FCEUP && HH)
// 		return (0xff00ff);
// 	if (FCELEFT && HV)
// 		return (0xffff00);
// 	if (FCEDOWN && HH)
// 		return (0xfffff0);
// 	if (FCERIGHT && HV)
// 		return (0xf0ffff);
// 	return (0);
// }

static void	render_wall(t_mapdata *map, double stripheight,
	int b, t_horizontal *it)
{
	int			i;
	int			wall;

	wall = (int)stripheight;
	(void)it;
	i = (HT / 2) - (wall / 2);
	while (i < (HT / 2) + (wall / 2))
	{
		if (i >= 0 && i < HT && b >= 0 && b < WH && HV)
			DATA[i * WH + b] = 0xffffff;
		if (i >= 0 && i < HT && b >= 0 && b < WH && HH)
			DATA[i * WH + b] = 0xb2b2b2;
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
