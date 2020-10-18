/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:33:00 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/18 17:15:51 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

int		iswall(double x, double y, t_mapdata *map)
{
	int	mapy;
	int	mapx;

	mapx = floor(x / (double)g_tiles);
	mapy = floor(y / (double)g_tiles);
	if (mapx >= 0 && mapx < PP && mapy >= 0 && mapy < g_rows)
		return ((MAP2D[mapy][mapx] == '1') || (MAP2D[mapy][mapx] == 'S'));
	return (0);
}

void	rayfacing(t_horizontal *it)
{
	FCEDOWN = ((ARC > 0) && (ARC < M_PI));
	FCEUP = !FCEDOWN;
	FCERIGHT = ((ARC < M_PI_2) || (ARC > (1.5 * M_PI)));
	FCELEFT = !FCERIGHT;
}

int		inwin(double x, double y, t_mapdata *map)
{
	return (((x >= 0) && (x <= WH)) || ((y >= 0) && (y <= HT)));
}

double	ft_horizontal(t_mapdata *map, t_horizontal *it)
{
	double	ax;
	double	ay;
	double	xstep;
	double	ystep;
	double	h;

	h = 0;
	ay = floor(PY / g_tiles) * g_tiles + (g_tiles * FCEDOWN);
	ax = PX + ((ay - PY) / tan(ARC));
	ystep = g_tiles * (FCEUP ? -1 : 1);
	xstep = g_tiles / tan(ARC);
	xstep *= (FCELEFT && xstep > 0) ? -1 : 1;
	xstep *= (FCERIGHT && xstep < 0) ? -1 : 1;
	if (FCEUP)
		h++;
	while (inwin(ax, ay - h, map) && !iswall(ax, ay - h, map))
	{
		ax += xstep;
		ay += ystep;
	}
	WALLX = ax;
	WALLY = ay;
	return (sqrtf((ay - PY) * (ay - PY) + (ax - PX) * (ax - PX)));
}

double	ft_vertical(t_mapdata *map, t_horizontal *it)
{
	double	ax;
	double	ay;
	double	xstep;
	double	ystep;
	double	hu;

	hu = 0;
	ax = floor(PX / g_tiles) * g_tiles + (g_tiles * FCERIGHT);
	ay = PY + ((ax - PX) * tan(ARC));
	xstep = g_tiles * (FCELEFT ? -1 : 1);
	ystep = g_tiles * tan(ARC);
	ystep *= (FCEUP && (ystep > 0)) ? -1 : 1;
	ystep *= (FCEDOWN && (ystep < 0)) ? -1 : 1;
	if (FCELEFT)
		hu++;
	while (inwin(ax - hu, ay, map) && !iswall(ax - hu, ay, map))
	{
		ax += xstep;
		ay += ystep;
	}
	WALLX = ax;
	WALLY = ay;
	return (sqrtf((ay - PY) * (ay - PY) + (ax - PX) * (ax - PX)));
}
