/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:40:11 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/11/20 11:52:08 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

float	sean(t_mapdata *map)
{
	if (MAP2D[(int)PY / g_tiles][(int)PX / g_tiles] == 'N')
		return (RAD(270));
	else if (MAP2D[(int)PY / g_tiles][(int)PX / g_tiles] == 'W')
		return (RAD(180));
	else if (MAP2D[(int)PY / g_tiles][(int)PX / g_tiles] == 'S')
		return (RAD(90));
	else if (MAP2D[(int)PY / g_tiles][(int)PX / g_tiles] == 'E')
		return (RAD(0));
	return (0);
}

void	picktxt(t_horizontal *it)
{
	if (FCEUP && HH)
		TXTNUM = 1;
	if (FCELEFT && HV)
		TXTNUM = 2;
	if (FCEDOWN && HH)
		TXTNUM = 3;
	if (FCERIGHT && HV)
		TXTNUM = 0;
}

void	texture(t_mapdata *map)
{
	int	usless;
	int uslesser;

	(TXTIMG = mlx_xpm_file_to_image(MLX, EA, &uslesser, &uslesser))
		? 0 : ft_error("wrong ea path");
	TXTDATA[0] = (int *)mlx_get_data_addr(TXTIMG, &usless, &usless, &usless);
	(TXTIMG = mlx_xpm_file_to_image(MLX, NO, &uslesser, &uslesser))
		? 0 : ft_error("wrong no path");
	TXTDATA[1] = (int *)mlx_get_data_addr(TXTIMG, &usless, &usless, &usless);
	(TXTIMG = mlx_xpm_file_to_image(MLX, WE, &uslesser, &uslesser))
		? 0 : ft_error("wrong we path");
	TXTDATA[2] = (int *)mlx_get_data_addr(TXTIMG, &usless, &usless, &usless);
	(TXTIMG = mlx_xpm_file_to_image(MLX, SO, &uslesser, &uslesser))
		? 0 : ft_error("wrong so path");
	TXTDATA[3] = (int *)mlx_get_data_addr(TXTIMG, &usless, &usless, &usless);
}
