/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 00:14:47 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/28 13:05:33 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

int		ft_atoi(const char *str)
{
	int result;
	int signe;

	result = 0;
	signe = 1;
	while (((*str >= 9 && *str <= 13) || *str == 32) && *str)
		str++;
	if (*str == '-')
	{
		signe = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		if (result < 0 && signe < 0)
			return (0);
		if (result < 0 && signe > 0)
			return (-1);
		result = result * 10 + *str - '0';
		str++;
	}
	return (signe * result);
}

void	ft_init(t_mapdata *map)
{
	map->width = 0;
	map->height = 0;
	map->north = 0;
	map->south = 0;
	map->east = 0;
	map->maponestr = 0;
	map->sprite = 0;
	map->west = 0;
	map->mapcheck = 0;
	MLX = 0;
	MAP2D = 0;
	DATA = 0;
	IMAGE = 0;
	PY = 0;
	KEY_S1 = 0;
	KEY_1 = 0;
	KEY_0 = 0;
	KEY_S0 = 0;
	LOL = 0;
	PP = 0;
	SCREEN = 0;
	map->wdis = 0;
	map->dwdx = sin(ANGLE) * map->wdis;
	map->dwdy = cos(ANGLE) * map->wdis;
	map->drota = 2 * (M_PI / 180);
}

void	ft_read(int fd, t_mapdata *map)
{
	char		*line;
	int			ret;

	while (1)
	{
		ret = get_next_line(fd, &line);
		if (line[0] == 'R' && line[1] == ' ' && (MCHECK++ || 1))
			ft_fetch(line, &HT, &WH, map);
		if ((line[0] == '1' || line[ft_strlen(line) - 1] == '1') && MCHECK < 8)
			ft_error("map isn't last in the file");
		if (MCHECK == 8)
			if (helpread(line, map))
				continue;
		(line[0] == 'N' && line[1] == 'O') ? ft_north(map, line) : 0;
		(line[0] == 'S' && line[1] == 'O') ? ft_south(map, line) : 0;
		(line[0] == 'W' && line[1] == 'E') ? ft_west(map, line) : 0;
		(line[0] == 'E' && line[1] == 'A') ? ft_east(map, line) : 0;
		(line[0] == 'S' && line[1] == ' ') ? ft_sprite(map, line) : 0;
		(line[0] == 'F' && line[1] == ' ') ? ft_floor(map, line) : 0;
		(line[0] == 'C' && line[1] == ' ') ? ft_ceeling(map, line) : 0;
		free(line);
		if (ret == 0)
			break ;
	}
}

void	ft_matrix(t_mapdata *map, char *line)
{
	char	*box;

	box = ft_strdup(line);
	if (!MAP0)
		MAP0 = ft_strdup("");
	MAP0 = ft_strjoin(MAP0, box);
	MAP0 = ft_strjoin(MAP0, ft_strdup("\n"));
}

void	ft_helpdrawasquare(t_mapdata *map)
{
	RAYDIST = malloc(sizeof(int *) * WH);
	ft_lstadd_front(&g_mylist, ft_lstnew(RAYDIST));
	ft_drawaplayer(map);
}
