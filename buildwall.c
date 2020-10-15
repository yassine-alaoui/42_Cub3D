#include "ray.h"
#include "lib.h"

static void	render_wall(t_info *info, int x, int bot, int top)
{
	float	texture_x;
	float	texture_y;
	int		y;
	int		wall_face;

	if (info->ray[x].is_vert)
	{
		texture_x = info->ray[x].wall_y - (int)info->ray[x].wall_y;
		texture_x *= TEXTURE_SIZE;
		wall_face = info->ray[x].face_lr;
	}
	else
	{
		texture_x = info->ray[x].wall_x - (int)info->ray[x].wall_x;
		texture_x *= TEXTURE_SIZE;
		wall_face = info->ray[x].face_ud;
	}
	y = top - 1;
	while (++y < bot)
	{
		texture_y = (y + (info->ray[x].stip_height / 2) - (info->res_y / 2))
		* ((float)TEXTURE_SIZE / info->ray[x].stip_height);
		info->img.data[y * info->res_x + x] =
		info->tex[wall_face].tex[(int)texture_x][(int)texture_y];
	}
}

static void	render_ceiling(t_info *info, int x, int top)
{
	while (top >= 0)
	{
		info->img.data[top * info->res_x + x] = info->c;
		top--;
	}
}

static void	render_floor(t_info *info, int x, int bot)
{
	while (bot < info->res_y)
	{
		info->img.data[bot * info->res_x + x] = info->f;
		bot++;
	}
}

void		generete_wall(t_mapdata *map, t_horizontal *it, double theone)
{
	int		i;
	int		top_pix;
	int		bot_pix;
	int		stripheight;
	float	per_dist;

	i = -1;
	per_dist = theone * cos(ARC - ANGLE;
	stripheight = (g_tiles / per_dist) * ((info->res_x / 2) / (tan(info->fov / 2)));
	top_pix = (info->res_y / 2) - (info->ray[i].stip_height / 2);
	top_pix = (top_pix < 0) ? 0 : top_pix;
	bot_pix = (info->res_y / 2) + (info->ray[i].stip_height / 2);
	bot_pix = (bot_pix > info->res_y) ? info->res_y : bot_pix;
	render_ceiling(info, i, top_pix);
	render_floor(info, i, bot_pix);
	render_wall(info, i, bot_pix, top_pix);
}