/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:40:11 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/18 20:43:35 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

void		texture(t_horizontal *it, t_mapdata *map)
{
	int	usless;
	int uslesser;

	TXTIMG = mlx_xpm_file_to_image(MLX, EA, &uslesser, &uslesser);
	TXTDATA = (int *)mlx_get_data_addr(TXTIMG, &usless, &usless, &usless);
}
