/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:34:09 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/11/21 18:54:50 by yaalaoui         ###   ########.fr       */
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
	size = SPRITES[id].size;
	while (++i < size - 1)
	{
		if (SPRITES[id].x_off + i <= 0 || SPRITES[id].x_off + i >= WH)
			continue ;
		if (RAYDIST[(int)(SPRITES[id].x_off + i)] < SPRITES[id].dist)
			continue ;
		j = -1;
		while (++j < size - 1)
		{
			if (SPRITES[id].y_off + j <= 0 || SPRITES[id].y_off + j >= HT)
				continue ;
			c = map->sdata[(int)((g_tiles) *
					(g_tiles * j / (int)size) + (g_tiles * i / (int)size))];
			if (c != map->sdata[0])
				DATA[(int)((j + SPRITES[id].y_off) *
				WH + (i + SPRITES[id].x_off))] = c;
		}
	}
}

void	to_sort(t_mapdata *map)
{
	int				i;
	int				j;
	t_sprite		tmp;

	i = 0;
	while (i < g_count - 1)
	{
		j = i;
		while (j < g_count - 1)
		{
			if (SPRITES[j].dist < SPRITES[j + 1].dist)
			{
				tmp = SPRITES[j];
				SPRITES[j] = SPRITES[j + 1];
				SPRITES[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	to_sprite(t_mapdata *map, int m)
{
	float	angle;
	int		k;

	m = -1;
	k = -1;
	to_sort(map);
	angle = 0;
	while (++k < g_count)
	{
		SPRITES[k].dist = sqrtf(((SPRITES[k].x) - PX) * ((SPRITES[k].x) - PX)
			+ ((SPRITES[k].y) - PY) * ((SPRITES[k].y) - PY));
		angle = atan2f(SPRITES[k].y - PY, SPRITES[k].x - PX);
		while (angle - ANGLE > M_PI)
			angle -= 2 * M_PI;
		while (angle - ANGLE < -M_PI)
			angle += 2 * M_PI;
		SPRITES[k].size = (WH / SPRITES[k].dist) * g_tiles;
		SPRITES[k].y_off = HT / 2 - (int)SPRITES[k].size / 2;
		SPRITES[k].x_off = ((DEG(angle) - DEG(ANGLE)) * WH)
		/ (float)g_tiles + ((WH / 2.0f) - (int)SPRITES[k].size / 2.0f);
		draw_sprite(map, k);
	}
}

void	init_spt(t_mapdata *map)
{
	int			i;
	int			j;
	int			k;

	i = -1;
	k = 0;
	if (!(SPRITES = malloc(sizeof(t_sprite) * (g_count))))
		ft_error("");
	ft_lstadd_front(&g_mylist, ft_lstnew(SPRITES));
	(map->simg = mlx_xpm_file_to_image(MLX, S, &SH, &SW)) ==
		0 ? ft_error("wrong sprite extension") : 0;
	map->sdata = (int *)mlx_get_data_addr(map->simg, &DT, &DT1, &DT1);
	while (MAP2D[++i] != 0 && (j = -1) && (k < g_count))
		while (MAP2D[i][++j] != 0 && (k < g_count))
			if (MAP2D[i][j] == '2')
			{
				SPRITES[k].x_off = 0;
				SPRITES[k].y_off = 0;
				SPRITES[k].size = 0;
				SPRITES[k].x = (j + 0.5f) * g_tiles;
				SPRITES[k].y = (i + 0.5f) * g_tiles;
				SPRITES[k].dist = sqrtf(((SPRITES[k].x) - PX) * ((SPRITES[k].x)
					- PX) + ((SPRITES[k].y) - PY) * ((SPRITES[k].y) - PY));
				k++;
			}
}
