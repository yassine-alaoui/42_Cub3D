/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexandsome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:51:47 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/03/10 17:05:10 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

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
