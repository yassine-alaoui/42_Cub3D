/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapstuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:33:27 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/03/11 13:40:09 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		wallconditions(t_mapdata *map, int *i, int *j)
{
	if (MAP2D[*i][*j] == '0' || MAP2D[*i][*j] == '2' || MAP2D[*i][*j] == 'N' ||
		MAP2D[*i][*j] == 'S' || MAP2D[*i][*j] == 'W' || MAP2D[*i][*j] == 'E')
	{
		if (MAP2D[*i][*j - 1] == ' ' || MAP2D[*i][*j + 1] == ' '
			|| MAP2D[*i - 1][*j] == ' ' || MAP2D[*i + 1][*j] == ' ')
			return (1);
		if (*j > (int)ft_strlen(MAP2D[*i - 1]) - 1 && !(MAP2D[*i - 1] == 0))
			return (1);
		if (*j > (int)ft_strlen(MAP2D[*i + 1]) - 1 && !(MAP2D[*i + 1] == 0))
			return (1);
	}
	return (0);
}

void	continuetreatingthatmap(t_mapdata *map)
{
	static int		i = -1;
	static int		j;

	while (MAP2D[++i])
	{
		ft_lstadd_front(&g_mylist, ft_lstnew((MAP2D[i])));
		if ((MAP2D[i][0] != '1' && MAP2D[i][0] != ' ')
			|| (MAP2D[i][ft_strlen(MAP2D[i]) - 1] != '1'
			&& MAP2D[i][ft_strlen(MAP2D[i]) - 1] != ' '))
			ft_error("map extreems aren't closed");
		j = -1;
		while (MAP2D[i][++j])
		{
			if (i == 0 || i == g_rows - 1)
				if (MAP2D[i][j] != '1' && MAP2D[i][j] != ' ')
					ft_error("map extreems  aren't closed");
			if (wallconditions(map, &i, &j) && j > 1 && i < g_rows && i > 1)
				ft_error("map isn't closed");
		}
	}
}

int		helptreatingthatmap(char c)
{
	if (c != '1' && c != '2' && c != '0' && c != 'N'
		&& c != 'S' && c != 'E' && c != 'W' && c != ' ')
		return (0);
	else
		return (1);
}

int		helpread(char *line, t_mapdata *map)
{
	if (line[ft_strlen(line) - 1] == '1' && LOL == 0)
		LOL = 1;
	if (LOL == 1 && line[ft_strlen(line) - 1] != '1')
		ft_error("map isn't closed");
	ft_matrix(map, line);
	return (0);
}

void	treatthatmap(t_mapdata *map)
{
	static int i = -1;
	static int j = -1;
	static int p = 0;

	continuetreatingthatmap(map);
	while (MAP2D[++i])
	{
		j = -1;
		(PP < (int)ft_strlen(MAP2D[i])) ? PP = (int)ft_strlen(MAP2D[i]) : PP;
		while (MAP2D[i][++j])
		{
			if ((MAP2D[i][j] == 'N' || MAP2D[i][j] == 'W'
				|| MAP2D[i][j] == 'E' || MAP2D[i][j] == 'S') && p == 0)
			{
				p = 1;
				(PX = (j * 32)) && (PY += (i * 32));
			}
			else if ((MAP2D[i][j] == 'N' || MAP2D[i][j] == 'W'
				|| MAP2D[i][j] == 'E' || MAP2D[i][j] == 'S') && p == 1)
				ft_error("multiplayer game");
			if (!helptreatingthatmap(MAP2D[i][j]))
				ft_error("wrong character");
		}
	}
	if (p == 0)
		ft_error("there's no player");
}
