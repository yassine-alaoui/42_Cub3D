/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildwall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:26:44 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/21 14:14:38 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

static void	ft_drawceeling(int wall, t_mapdata *map, int b)
{
	int			i;
	int			j;

	j = 0;
	i = (HT / 2) - (wall / 2);
	while (j < i)
	{
		if (j >= 0 && j < HT && b >= 0 && b < WH)
			DATA[j * WH + b] = HEXC;
		j++;
	}
}

static void	ft_drawfloor(int wall, t_mapdata *map, int b)
{
	int			i;
	int			j;

	j = HT;
	i = (HT / 2) + (wall / 2);
	while (i < j)
	{
		if (i >= 0 && i < HT && b >= 0 && b < WH)
			DATA[i * WH + b] = HEXF;
		i++;
	}
}

static void	ft_drawwall(int wall, t_mapdata *map,
	t_horizontal *it, int b)
{
	float	i;
	float	y;
	float	offsetx;

	if (HV)
		offsetx = (int)WALLY % g_tiles;
	else
		offsetx = (int)WALLX % g_tiles;
	i = (HT / 2) - (wall / 2);
	y = 0;
	picktxt(it);
	while (i < (HT / 2) + (wall / 2))
	{
		if (i >= 0 && i < HT && b >= 0 && b < WH)
			DATA[(int)i * WH + b] = TXTDATA[TXTNUM][(int)offsetx
				+ (g_tiles * (int)y)];
		i++;
		y += (float)g_tiles / wall;
	}
}

static void	render_wall(t_mapdata *map, double stripheight,
	int b, t_horizontal *it)
{
	int	wall;

	wall = (int)stripheight;
	ft_drawwall(wall, map, it, b);
	ft_drawceeling(wall, map, b);
	ft_drawfloor(wall, map, b);
}

void		generete_wall(t_mapdata *map, t_horizontal *it,
	int b, double theone)
{
	double		prjplane;
	double		dist;
	double		stripheight;

	dist = theone * cos(ARC - ANGLE);
	prjplane = (WH / 2) / tan(M_PI / 6);
	stripheight = (g_tiles / dist) * prjplane;
	render_wall(map, stripheight, b, it);
}
