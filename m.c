/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:02:34 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/17 18:50:25 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

void	init(t_horizontal *it)
{
	it->dx = 0;
	it->x = 0;
	it->wallx = 0;
	it->dy = 0;
	it->y = 0;
	it->wally = 0;
	it->facedown = 0;
	it->faceup = 0;
	it->faceleft = 0;
	it->faceright = 0;
}

int		main(/*int argc, char **argv*/)
{
	int			fd;
	t_mapdata	*map;

	g_tiles = 64;
	if (!(map = malloc(sizeof(t_mapdata))))
		ft_error("can't be allocated");
	ft_init(map);
	g_mylist = ft_lstnew(0);
	MLX = mlx_init();
	fd = open("map.cub", O_RDONLY);
	ft_intro(fd, map);
	g_mlx_win = mlx_new_window(MLX, WH, HT, "CUB3D");
	IMAGE = mlx_new_image(MLX, WH, HT);
	DATA = (int *)mlx_get_data_addr(IMAGE, &SIZELINE, &ENDIAN, &ENDIAN);
	// if (argc == 2)
	// {
		ft_helpdrawasquare(map);
	// }
	// else
	// 	ft_error("not epic");
	mlx_put_image_to_window(MLX, g_mlx_win, IMAGE, 0, 0);
	mlx_loop_hook(MLX, &loop_me, map);
	// ft_lstclear(&g_mylist);
	mlx_loop(MLX);
}
