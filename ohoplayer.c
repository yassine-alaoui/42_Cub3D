/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ohoplayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 03:54:40 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/16 14:20:13 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_quit()
{
	// if (key == 53)
	// 	ft_error("game over");
	return (0);
}

int		key_released(int key, t_mapdata *map)
{
	if (key == LEFT || key == RIGHT)
		KEY_S0 = 0;
	if (key == DOWN || key == UP)
		KEY_S1 = 0;
	if (key == 53)
		ft_error("game over");
	return (0);
}

int		key_pressed(int key, t_mapdata *map)
{
	if (key == LEFT || key == RIGHT)
	{
		KEY_0 = key;
		KEY_S0 = 1;
	}
	if (key == DOWN || key == UP)
	{
		KEY_1 = key;
		KEY_S1 = 1;
	}
	return (0);
}

int		ft_iswall(t_mapdata *map)
{
	int newx;
	int newy;
	int newbx;
	int newby;

	if (PX < 0 || PY < 0)
		return (1);
	newy = floor((DWY + PY) / g_tiles);
	newx = floor((DWX + PX) / g_tiles);
	newby = floor((DWY + PY) / g_tiles);
	newbx = floor((DWX + PX) / g_tiles);
	if (MAP2D[newy][newx] == '1' || MAP2D[newy][newbx] == '1'
		|| MAP2D[newby][newx] == '1' || MAP2D[newby][newbx] == '1')
		return (1);
	return (0);
}

int		loop_me(t_mapdata *map)
{
	mlx_hook(g_mlx_win, 2, 0, &key_pressed, map);
	mlx_hook(g_mlx_win, 3, 0, &key_released, map);
	mlx_hook(g_mlx_win, 17, 0, &ft_quit, map);
	if (KEY_S0)
	{
		ANGLE = fmod(ANGLE, M_PI * 2);
		(ANGLE < 0) ? ANGLE += M_PI * 2 : 0;
		(KEY_0 == LEFT) ? ANGLE = ANGLE - DRT : 0;
		(KEY_0 == RIGHT) ? ANGLE = ANGLE + DRT : 0;
	}
	DWX = cos(ANGLE) * DWD * (KEY_1 == DOWN ? -1 : 1);
	DWY = sin(ANGLE) * DWD * (KEY_1 == DOWN ? -1 : 1);
	if (KEY_S1 && !ft_iswall(map))
	{
		(PX += DWX);
		(PY += DWY);
	}
	mlx_destroy_image(MLX, IMAGE);
	IMAGE = mlx_new_image(MLX, WH, HT);
	DATA = (int *)mlx_get_data_addr(IMAGE, &SIZELINE, &ENDIAN, &ENDIAN);
	ft_helpdrawasquare(map);
	mlx_put_image_to_window(MLX, g_mlx_win, IMAGE, 0, 0);
	return (0);
}
