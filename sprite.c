/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:34:09 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/28 19:14:57 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

void	draw_sprite(t_mapdata *map, int id)
{
	int		i;
	int		j;
	int		c;
	float	size;

	i = -1;
	c = 0;
	size = SPRITES[id].size;
	while (++i < size)
	{
		if (SPRITES[id].x_off + i < 0 || SPRITES[id].x_off + i > WH)
			continue ;
		if (RAYDIST[(int)(SPRITES[id].x_off + i)] <= SPRITES[id].dist)
			continue ;
		j = -1;
		while (++j < size)
		{
			if (SPRITES[id].y_off + j < 0 || SPRITES[id].y_off + j > HT)
				continue ;
			c = SPRITES->sdata[(int)(g_tiles * (g_tiles * j / (int)size) + (g_tiles * i / (int)size))];
			if (c != SPRITES->sdata[0] && j + 1 <= size && i + 1 <= size)
				DATA[(int)((j + SPRITES[id].y_off) *
				WH + (i + SPRITES[id].x_off))] = c;
		}
	}
}

void	to_sort(t_sprite *spt)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = -1;
	while (++i < g_count)
	{
		j = -1;
		while (++j < g_count - i)
		{
			if (spt[j].dist < spt[j + 1].dist)
			{
				tmp = spt[j];
				spt[j] = spt[j + 1];
				spt[j + 1] = tmp;
			}
		}
	}
}

void	to_sprite(t_mapdata *map, int m)
{
	float	angle;
	const float pplane_dist = (WH / 2.0F) / tanf((RAD(60)) / 2);
	int		k;

	k = -1;
	while (++m < g_count)
		SPRITES[m].dist = sqrtf(((SPRITES[m].x) - PX) *
			((SPRITES[m].x) - PX) + ((SPRITES[m].y) - PY) * ((SPRITES[m].y) - PY));
	to_sort(SPRITES);
	while (++k < g_count)
	{
		// SPRITES[k].dist = sqrtf(((SPRITES[k].x) - PX) *
		// 	((SPRITES[k].x) - PX) + ((SPRITES[k].y) - PY) * ((SPRITES[k].y) - PY));
		angle = atan2f(SPRITES[k].y - PY, SPRITES[k].x - PX);
		while (angle - ANGLE > M_PI)
			angle -= 2 * M_PI;
		while (angle - ANGLE < -M_PI)
			angle += 2 * M_PI;
		SPRITES[k].size = ((float)g_tiles / SPRITES[k].dist * pplane_dist);
		SPRITES[k].y_off = HT / 2 - (int)SPRITES[k].size / 2;
		SPRITES[k].x_off = ((DEG(angle) - DEG(ANGLE)) * WH)
		/ (float)g_tiles + ((WH / 2) - (int)SPRITES[k].size / 2);
		draw_sprite(map, k);
	}
}

void	init_spt(t_mapdata *map)
{
	int			i;
	int			j;
	int			k;
	// t_SPRITES	*SPRITES;

	i = -1;
	k = 0;
	if (!(SPRITES = malloc(sizeof(t_sprite) * (g_count + 1))))
		ft_error("");
	ft_lstadd_front(&g_mylist, ft_lstnew(SPRITES));
	SPRITES->simg = mlx_xpm_file_to_image(MLX, S, &SH, &SW);
	SPRITES->sdata = (int *)mlx_get_data_addr(SPRITES->simg, &DT, &DT1, &DT1);
	while (MAP2D[++i] != 0 && (j = -1) && (k < g_count))
	{
		while (MAP2D[i][++j] != 0 && (k < g_count))
		{
			if (MAP2D[i][j] == '2')
			{
				SPRITES[k].x = (j + 0.5f) * g_tiles;
				SPRITES[k].y = (i + 0.5f) * g_tiles;
				k++;
			}
		}
	}
}
