/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helptools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:51:47 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/11/21 20:35:49 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

void	ft_small_check(char *line, t_mapdata *map, int notmap)
{
	if (line[0] == 'R' && line[1] == ' ' && (MCHECK++ || 1))
		ft_fetch(line, map);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		ft_north(map, line);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		ft_south(map, line);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		ft_west(map, line);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		ft_east(map, line);
	else if (line[0] == 'S' && line[1] == ' ')
		ft_sprite(map, line);
	else if (line[0] == 'F' && line[1] == ' ')
		ft_floor(map, line);
	else if (line[0] == 'C' && line[1] == ' ')
		ft_ceeling(map, line);
	else if (line[0] != '\0' && MCHECK < 8)
		ft_error("there is a none empty line");
	else if (line[0] != ' ' && line[0] != '1' && MCHECK == 8 && !notmap)
		ft_error("something is wrong with the map");
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (i != n - 1 && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

double	colmdist(t_mapdata *map, t_horizontal *it)
{
	double dist;
	double hdist;
	double vdist;

	rayfacing(it);
	HH = 0;
	HV = 0;
	dist = 0;
	hdist = ft_horizontal(map, it);
	vdist = ft_vertical(map, it);
	if (hdist < vdist)
	{
		WALLX = WALLHX;
		WALLY = WALLHY;
		dist = hdist;
		HH = 1;
	}
	else
	{
		WALLX = WALLVX;
		WALLY = WALLVY;
		dist = vdist;
		HV = 1;
	}
	return (dist);
}
