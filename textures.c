/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:40:11 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/20 18:15:41 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

void	picktxt(t_horizontal *it)
{
	if (FCEUP && HH)
		TXTNUM = 3;
	if (FCELEFT && HV)
		TXTNUM = 0;
	if (FCEDOWN && HH)
		TXTNUM = 1;
	if (FCERIGHT && HV)
		TXTNUM = 2;
}

void	texture(t_horizontal *it, t_mapdata *map)
{
	int	usless;
	int uslesser;

	TXTIMG = mlx_xpm_file_to_image(MLX, EA, &uslesser, &uslesser);
	TXTDATA[0] = (int *)mlx_get_data_addr(TXTIMG, &usless, &usless, &usless);
	TXTIMG = mlx_xpm_file_to_image(MLX, NO, &uslesser, &uslesser);
	TXTDATA[1] = (int *)mlx_get_data_addr(TXTIMG, &usless, &usless, &usless);
	TXTIMG = mlx_xpm_file_to_image(MLX, WE, &uslesser, &uslesser);
	TXTDATA[2] = (int *)mlx_get_data_addr(TXTIMG, &usless, &usless, &usless);
	TXTIMG = mlx_xpm_file_to_image(MLX, SO, &uslesser, &uslesser);
	TXTDATA[3] = (int *)mlx_get_data_addr(TXTIMG, &usless, &usless, &usless);
}
