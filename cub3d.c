/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 00:14:47 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/11/21 14:43:10 by yaalaoui         ###   ########.fr       */
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
	MAP2DB = 0;
	DATA = 0;
	IMAGE = 0;
	PY = 0;
	KEY_S1 = 0;
	KEY_1 = 0;
	KEY_2 = 0;
	KEY_0 = 0;
	KEY_S0 = 0;
	KEY_S2 = 0;
	LOL = 0;
	PP = 0;
	SCREEN = 0;
}

void	ft_read(int fd, t_mapdata *map)
{
	char		*line;
	int			ret;
	static int	notmap = 1;

	while (1)
	{
		ret = get_next_line(fd, &line);
		if ((line[0] == '1' || line[0] == ' ') && MCHECK < 8)
			ft_error("map isn't last in the file");
		if (MCHECK == 8 && (line[0] == ' ' || line[0] == '1')
			&& notmap == 1)
			notmap = 0;
		if (MCHECK == 8 && line[0] != '\0' && notmap == 1)
			ft_error("not an empty line");
		ft_small_check(line, map, notmap);
		if (MCHECK == 8 && notmap == 0)
		{
			(PP < (int)ft_strlen(line)) ? PP = (int)ft_strlen(line) : PP;
			if (helpread(line, map))
				continue;
		}
		free(line);
		if (ret == 0)
			break ;
	}
}

void	ft_matrix(t_mapdata *map, char *line)
{
	char		*box;
	int			i;

	i = 0;
	box = ft_strdup(line);
	if (!MAP0)
		MAP0 = ft_strdup("");
	MAP0 = ft_strjoin(MAP0, box);
	MAP0 = ft_strjoin(MAP0, ft_strdup("\n"));
}

void	ft_helpdrawasquare(t_mapdata *map)
{
	static int tmp = 0;

	if (tmp == 0)
	{
		RAYDIST = malloc(sizeof(int *) * WH);
		ft_lstadd_front(&g_mylist, ft_lstnew(RAYDIST));
		tmp = 1;
	}
	ft_drawaplayer(map);
}
