/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexandsome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:51:47 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/18 19:11:37 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

void		ft_fhexa(int nb, t_mapdata *map)
{
	static int	i = 0;
	char		*xa;

	xa = "0123456789abcdef";
	FLOOR[i] = xa[nb / 16];
	i++;
	FLOOR[i] = xa[nb % 16];
	i++;
}

void		ft_chexa(int nb, t_mapdata *map)
{
	static int	i = 0;
	char		*xa;

	xa = "0123456789abcdef";
	CEELING[i] = xa[nb / 16];
	i++;
	CEELING[i] = xa[nb % 16];
	i++;
}

void		hexf(t_mapdata *map)
{
	int		i;
	int		b;
	char	*a;
	int		num;

	i = 0;
	a = 0;
	b = 0;
	while (FLOOR[i])
	{
		if (FLOOR[i] >= '0' && FLOOR[i] <= '9')
			num = FLOOR[i] - '0';
		if (FLOOR[i] >= 'A' && FLOOR[i] <= 'F')
			num = FLOOR[i] - 'A' + 10;
		if (FLOOR[i] >= 'a' && FLOOR[i] <= 'f')
			num = FLOOR[i] - 'a' + 10;
		HEXF = HEXF * 10 + num;
		i++;
	}
}

void		hexc(t_mapdata *map)
{
	int		i;
	int		b;
	char	*a;
	int		num;

	i = 0;
	a = 0;
	b = 0;
	while (CEELING[i])
	{
		if (CEELING[i] >= '0' && CEELING[i] <= '9')
			num = CEELING[i] - '0';
		if (CEELING[i] >= 'A' && CEELING[i] <= 'F')
			num = CEELING[i] - 'A' + 10;
		if (CEELING[i] >= 'a' && CEELING[i] <= 'f')
			num = CEELING[i] - 'a' + 10;
		HEXC = HEXC * 10 + num;
		i++;
	}
}

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
		// WALLHX = WALLX;
		// WALLHY = WALLY;
		dist = hdist;
		HH = 1;
	}
	else
	{
		// WALLVX = WALLX;
		// WALLVY = WALLY;
		dist = vdist;
		HV = 1;
	}
	return (dist);
}
