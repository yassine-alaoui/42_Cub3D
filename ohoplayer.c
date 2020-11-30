/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ohoplayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0010/02/23 03:54:40 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/11/30 12:56:00 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

int		ft_quit(void)
{
	ft_error("game over");
	return (0);
}

int		key_released(int key, t_mapdata *map)
{
	if (key == 259)
	{
		KEY_0 = 0;
		KEY_1 = 0;
		KEY_2 = 0;
	}
	(key == LEFT || key == RIGHT) ? KEY_S0 = 0 : 0;
	(key == DOWN || key == UP) ? KEY_S1 = 0 : 0;
	(key == WLEFT || key == WRIGHT) ? KEY_S2 = 0 : 0;
	if (key == WLEFT || key == WRIGHT)
	{
		if (key == WLEFT)
			KEY_2 = 0;
		if (key == WRIGHT)
			KEY_2 = 0;
	}
	if (key == DOWN || key == UP)
	{
		if (key == DOWN)
			KEY_1 = 0;
		if (key == UP)
			KEY_1 = 0;
	}
	(key == 53) ? ft_error("game over") : 0;
	return (0);
}

int		key_pressed(int key, t_mapdata *map)
{
	if (key == LEFT || key == RIGHT)
	{
		if (key == LEFT)
			KEY_0 = 1;
		if (key == RIGHT)
			KEY_0 = -1;
		KEY_S0 = 1;
	}
	if (key == WLEFT || key == WRIGHT)
	{
		if (key == WLEFT)
			KEY_2 = -1;
		if (key == WRIGHT)
			KEY_2 = 1;
		KEY_S2 = 1;
	}
	if (key == DOWN || key == UP)
	{
		if (key == DOWN)
			KEY_1 = -1;
		if (key == UP)
			KEY_1 = 1;
		KEY_S1 = 1;
	}
	return (0);
}

void	ft_movewasd(t_mapdata *map)
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		t;

	t = g_tiles;
	y = MAP2D[(int)(PY + (KEY_1 * sin(ANGLE) * 10)) / (t)][(int)PX / (t)];
	y1 = MAP2D[(int)(PY + (KEY_2 * sin(RAD(ANGLE + 90)) * 10))
	/ (t)][(int)PX / (t)];
	x = MAP2D[(int)PY / (t)][(int)(PX + (KEY_1 * cos(ANGLE) * 10)) / (t)];
	x1 = MAP2D[(int)PY / (t)][(int)(PX + (KEY_2
	* cos(RAD(ANGLE + 90)) * 10)) / (t)];
	ANGLE = fmod(ANGLE, 2 * M_PI);
	if (ANGLE < 0)
		ANGLE += 2 * M_PI;
	if (KEY_S0)
		ANGLE = ANGLE + (KEY_0 * 0.025);
	if (y != '1' && y != '2' && y1 != '1' && y1 != '2')
		PY = PY + (KEY_1 * sin(ANGLE) * 4) +
			(KEY_2 * sin(RAD(ANGLE + 90)) * 2);
	if (x != '1' && x != '2' && x1 != '1' && x1 != '2')
		PX = PX + (KEY_1 * cos(ANGLE) * 4) +
			(KEY_2 * cos(RAD(ANGLE + 90)) * 2);
}

int		loop_me(t_mapdata *map)
{
	mlx_hook(g_mlx_win, 2, 0, &key_pressed, map);
	mlx_hook(g_mlx_win, 3, 0, &key_released, map);
	mlx_hook(g_mlx_win, 17, 0L, &ft_quit, map);
	ANGLE = fmod(ANGLE, 2 * M_PI);
	if (ANGLE < 0)
		ANGLE += 2 * M_PI;
	if (KEY_S0 == 1)
		ANGLE = ANGLE + ((KEY_0) * 0.06);
	ft_movewasd(map);
	mlx_destroy_image(MLX, IMAGE);
	IMAGE = mlx_new_image(MLX, WH, HT);
	DATA = (int *)mlx_get_data_addr(IMAGE, &SIZELINE, &ENDIAN, &ENDIAN);
	ft_helpdrawasquare(map);
	mlx_put_image_to_window(MLX, g_mlx_win, IMAGE, 0, 0);
	return (0);
}
