/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:04:59 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/14 19:07:22 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>
#include <string.h>
#include "ray.h"

int		get_next_line(int fd, char **line)
{
	static char	*last[1024];
	char		*tmp;
	char		*pmt;

	if (!last[fd])
		last[fd] = ft_strdup("");
	if (!line || fd < 0)
		return (-1);
	if (ft_fill(&last[fd], fd) < 0)
		return (-1);
	if ((ft_strchr(last[fd], '\n')))
	{
		tmp = last[fd];
		*line = ft_substr(last[fd], 0, ft_strchr(last[fd], '\n') - last[fd]);
		last[fd] = ft_strdup(last[fd] + (ft_strchr(last[fd],
		'\n') - last[fd] + 1));
		free(tmp);
		return (1);
	}
	else
		*line = ft_strdup(last[fd]);
	pmt = last[fd];
	last[fd] = NULL;
	free(pmt);
	return (0);
}

int		ft_fill(char **last, int fd)
{
	int		ret;
	char	*buf;
	char	**tmp;

	while (!ft_strchr(last[0], '\n'))
	{
		if (!(buf = malloc(1000 + 1)) ||
			(ret = read(fd, buf, 1000)) < 0)
			return (-1);
		buf[ret] = '\0';
		last[0] = ft_strjoin(last[0], buf);
		if (ret == 0)
		{
			tmp = last;
			last = 0;
			return (0);
		}
	}
	return (1);
}

void	ft_drawasquare(int a, int b, t_mapdata *map)
{
	int			i;
	int			j;

	i = 0;
	while (i <= g_tiles)
	{
		j = 0;
		while (j <= g_tiles)
		{
			DATA[(j + b) * WH + (i + a)] = 0x0fffff;
			j++;
		}
		i++;
	}
}

void	ft_drawline(t_mapdata *map, float raylength, t_horizontal *it)
{
	int	j;

	j = 0;
	while (j <= raylength)
	{
		DATA[(int)(PY + sin(ARC) * j) *
			WH + (int)(PX + cos(ARC) * j)] = 0xff0000;
		j++;
	}
}

void	ft_drawaplayer(t_mapdata *map)
{
	double			theone;
	int				i;
	t_horizontal	*it;

	it = malloc(sizeof(t_horizontal));
	init(it);
	i = 0;
	ft_lstadd_front(&g_mylist, ft_lstnew(it));
	ARC = ANGLE - (M_PI / 6);
	DATA[(int)(PY) * WH + (int)(PX)] = 0x00ff00;
	while (i < WH)
	{
		if (ARC < 0)
			ARC += 2 * M_PI;
		if (ARC > M_PI * 2)
			ARC -= (M_PI * 2);
		theone = colmdist(map, it);
		ft_drawline(map, theone, it);
		ARC += (M_PI / 3) / WH;
		i++;
	}
}
