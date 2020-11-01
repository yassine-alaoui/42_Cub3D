/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:02:34 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/28 19:11:01 by yaalaoui         ###   ########.fr       */
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

void	mlx_stuff(t_mapdata *map)
{
	g_mlx_win = mlx_new_window(MLX, WH, HT, "CUB3D");
	IMAGE = mlx_new_image(MLX, WH, HT);
	DATA = (int *)mlx_get_data_addr(IMAGE, &SIZELINE, &ENDIAN, &ENDIAN);
	ft_helpdrawasquare(map);
	mlx_put_image_to_window(MLX, g_mlx_win, IMAGE, 0, 0);
	if (SCREEN == 1)
	{
		save_bmp(map);
		ft_lstclear(&g_mylist);
		exit(1);
	}
	mlx_loop_hook(MLX, &loop_me, map);
	mlx_loop(MLX);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_mapdata	*map;

	g_tiles = 64;
	g_count = 0;
	if (!(map = malloc(sizeof(t_mapdata))))
		ft_error("can't be allocated");
	ft_init(map);
	g_mylist = ft_lstnew(0);
	MLX = mlx_init();
	fd = open(argv[1], O_RDONLY);
	if (argc == 3)
		((ft_strncmp(argv[2], "--save", 6) == 0)) ?
			SCREEN = 1 : ft_error("wrong argument");
	(argc == 2 || (argc == 3 && SCREEN == 1)) ? ft_intro(fd, map)
		: ft_error("where is my map");
	ANGLE = sean(map);
	init_spt(map);
	mlx_stuff(map);
}
