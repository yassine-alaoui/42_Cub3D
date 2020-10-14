#include "lib.h"
#include "ray.h"


int		iswall(double x, double y, t_mapdata *map)
{
	int mapy = floor(y / (double)g_tiles);
	int mapx = floor(x / (double)g_tiles);
	if (mapx >= 0 && mapx < PP && mapy >=0 && mapy < g_rows)
		return ((MAP2D[mapy][mapx] == '1'));
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
	double ax;
	double ay;
	double xstep;
	double ystep;
	int h = 0;
	
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
	double ax;
	double ay;
	double xstep;
	double ystep;
	int hu = 0;

	ax = floor(PX / 32) * 32 + (32 * FCERIGHT);
	ay = PY + ((ax - PX) * tan(ARC));
	xstep = 32 * (FCELEFT ? -1 : 1);
	ystep = 32 * tan(ARC);
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

double	colmdist(t_mapdata *map, t_horizontal *it)
{
	double dist;
	double hdist = 0;
	double vdist = 0;

	rayfacing(it);
	hdist = ft_horizontal(map, it);
	vdist = ft_vertical(map, it);
	if (hdist < vdist)
	{
		// WALLX = WALLHX;
		// WALLY = WALLHY;
		dist = hdist;
		// HH = 1;
	}
	else
	{
		// WALLX = WALLVX;
		// WALLY = WALLVY;
		dist = vdist;
		// HV = 1;
	}
	return (dist);
}

void	init(t_horizontal *it)
{
	it->dx = 0;
	it->x = 0;
	it->wallx = 0;
	it->dy = 0;
	it->y = 0;
	it->wally = 0;
	it->facedown = 0;
	it->faceup = 0;
	it->faceleft = 0;
	it->faceright = 0;
}