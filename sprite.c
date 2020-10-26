/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:34:09 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/26 18:55:08 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

void	draw_sprite1(t_mapdata *map, t_sprite *sprite, int id)
{
	int i;
	int	j;
	int c;
	int size;

	i = -1;
	size = sprite[id].size;
	while (++i < size)
	{
		if (sprite[id].x_off + i < 0 || sprite[id].x_off + i > WH)
			continue ;
		if (RAYDIST[(int)(sprite[id].x_off + i)] <= sprite[id].dist)
			continue ;
		j = -1;
		while (++j < size)
		{
			if (sprite[id].y_off + j < 0 || sprite[id].y_off + j > HT)
				continue ;
			c = sprite[id].sdata[64 * (64 * j / size) + (64 * i / size)];
			if (c != 0)
				DATA[(int)(j + sprite[id].y_off) *
				WH + (int)(i + sprite[id].x_off)] = c;
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

void	to_sprite(t_sprite *sprite, t_mapdata *map, int m, t_horizontal *it)
{
	float	angle;
	int		k;

	k = -1;
	while (++m < g_count)
		sprite[m].dist = sqrt((sprite[m].x - PX) *
			(sprite[m].x - PX) + (sprite[m].y - PY) * (sprite[m].y - PY));
	to_sort(sprite);
	while (++k < g_count)
	{
		sprite[k].dist = sqrt((sprite[m].x - PX) *
			(sprite[m].x - PX) + (sprite[m].y - PY) * (sprite[m].y - PY));
		angle = atan2(sprite[k].y - PY, sprite[k].x - PX);
		while (angle - ARC > M_PI)
			angle -= 2 * M_PI;
		while (angle - ARC < -M_PI)
			angle += 2 * M_PI;
		if (HT > WH)
			sprite[k].size = (HT / sprite[k].dist) * g_tiles;
		else
			sprite[k].size = (WH / sprite[k].dist) * g_tiles;
		sprite[k].y_off = HT / 2 - sprite[k].size / 2;
		sprite[k].x_off = (DEG(angle) - DEG(ARC)) * WH
		/ 60 + ((WH / 2) - (sprite[k].size / 2));
		draw_sprite1(map, sprite, k);
	}
}

void	init_spt(t_mapdata *map, t_horizontal *it)
{
	int			i;
	int			j;
	int			k;
	t_sprite	*sprite;

	i = -1;
	k = 0;
	(void)it;
	if (!(sprite = malloc(sizeof(t_sprite) * (g_count + 1))))
		ft_error("");
	ft_lstadd_front(&g_mylist, ft_lstnew(sprite));
	sprite->simg = mlx_xpm_file_to_image(MLX, S, &SH, &SW);
	// sprite->sdata = (int *)
	// 	mlx_get_data_addr(sprite->simg, &DT, &DT1, &DT1);
	while (MAP2D[++i] != 0 && (j = -1))
	{
		while (MAP2D[i][++j] != 0)
		{
			if (MAP2D[i][j] == '2')
			{
				sprite[k].x = (j + 0.5f) * (float)g_tiles;
				sprite[k].y = (i + 0.5f) * (float)g_tiles;
				k++;
			}
		}
	}
	// to_sprite(sprite, map, -1, it);
}
