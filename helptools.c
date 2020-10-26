/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexandsome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:51:47 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/26 19:37:58 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

double		colmdist(t_mapdata *map, t_horizontal *it)
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
