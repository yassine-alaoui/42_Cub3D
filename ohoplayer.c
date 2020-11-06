/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ohoplayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 03:54:40 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/28 18:43:13 by yaalaoui         ###   ########.fr       */
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
	if (key == LEFT || key == RIGHT)
		KEY_S0 = 0;
	if (key == DOWN || key == UP)
		KEY_S1 = 0;
	if (key == WLEFT || key == WRIGHT)
		KEY_S2 = 0;
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
	if (key == 53)
		ft_error("game over");
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
	if (MAP2D[(int)(PY + (KEY_1 * sin(ANGLE) * 8))
		/ (g_tiles)][(int)PX / (g_tiles)] != '1')
		if (MAP2D[(int)(PY + (KEY_2 * sin(ANGLE + RAD(90)) * 8)) / (g_tiles)]
			[(int)PX / (g_tiles)] != '1' && ((KEY_S2 == 1) || (KEY_S1 == 1)))
			PY = PY + (KEY_1 * sin(ANGLE) * 4) + (KEY_2 *
				sin(ANGLE + RAD(90)) * 4);
	if (MAP2D[(int)PY / (g_tiles)][(int)(PX + (KEY_1 * cos(ANGLE) * 8)) /
		(g_tiles)] != '1')
		if (MAP2D[(int)PY / (g_tiles)][(int)(PX + (KEY_2 * cos(ANGLE + RAD(90))
			* 8)) / (g_tiles)] != '1' && ((KEY_S2 == 1) || (KEY_S1 == 1)))
			PX = PX + (KEY_1 * cos(ANGLE) * 4) +
				(KEY_2 * cos(ANGLE + RAD(90)) * 4);
	mlx_clear_window(MLX, g_mlx_win);
	ft_helpdrawasquare(map);
	mlx_put_image_to_window(MLX, g_mlx_win, IMAGE, 0, 0);
	return (0);
}
