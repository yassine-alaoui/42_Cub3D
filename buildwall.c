/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildwall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:26:44 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/18 20:48:02 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

static void	ft_drawceeling(int wall, t_horizontal *it, t_mapdata *map, int b)
{
	int			i;
	int			j;

	j = 0;
	i = (HT / 2) - (wall / 2);
	(void)it;
	while (j < i)
	{
		if (i >= 0 && i < HT && b >= 0 && b < WH)
			DATA[j * WH + b] = HEXC;
		j++;
	}
}

static void	ft_drawfloor(int wall, t_horizontal *it, t_mapdata *map, int b)
{
	int			i;
	int			j;

	j = HT - 1;
	i = ((HT / 2) - (wall / 2)) + wall - 1;
	(void)it;
	while (i < j)
	{
		if (b >= 0 && b < WH)
			DATA[i * WH + b] = HEXF;
		i++;
	}
}

static void	ft_drawwall(int wall, t_mapdata *map,
	t_horizontal *it, int b)
{
	int	i;
	// int	texturecol;
	int	offsetx;
	int	offsety;

	if (HV)
		offsetx = WALLY % g_tiles;
	else
		offsetx = WALLX % g_tiles;
	(void)it;
	i = (HT / 2) - (wall / 2);
	while (i < (HT / 2) + (wall / 2))
	{
		offsety = (i - (HT / 2) - (wall / 2)) * (g_tiles / wall);
		// texturecol = TEXTURE[(g_tiles * offsety) + offsetx];
		if (i >= 0 && i < HT && b >= 0 && b < WH)
			DATA[i * WH + b] = TXTDATA[offsetx + (g_tiles * offsety)];
		i++;
	}
}

static void	render_wall(t_mapdata *map, double stripheight,
	int b, t_horizontal *it)
{
	int	wall;

	wall = (int)stripheight - 5;
	ft_drawwall(wall, map, it, b);
	ft_drawceeling(wall, it, map, b);
	ft_drawfloor(wall, it, map, b);
}

void		generete_wall(t_mapdata *map, t_horizontal *it, int b)
{
	double		prjplane;
	double		dist;
	double		stripheight;

	dist = colmdist(map, it) * cos(ARC - ANGLE);
	prjplane = (WH / 2) / tan(M_PI / 6);
	stripheight = (g_tiles / dist) * prjplane;
	render_wall(map, stripheight, b, it);
}
