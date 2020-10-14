/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 23:00:47 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/03/05 20:40:51 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_fetch(char *line, int *height, int *width, t_mapdata *map)
{
	static int	i = 0;
	static int	cond1 = 1;
	static int	cond2 = 1;
	static int	check = 0;

	while (line[i++] != '\0')
	{
		if (((line[i] == '0' && line[i + 1] == ' ') || line[i] == '-'))
			ft_error("impossible resolution");
		if (ft_isdigit(line[i]) && cond1 && (check += 1))
		{
			(*width = ft_atoi(line + i)) && (cond1 -= cond1);
			i += ft_intlen(*width);
		}
		if (ft_isdigit(line[i]) && !cond1 && cond2 && (check += 1))
		{
			*height = ft_atoi(line + i);
			i += ft_intlen(*height);
		}
		(ft_isdigit(line[i]) && !cond1 && !cond2) ? check++ : 0;
	}
	(!(line[1] == ' ')) ? ft_error("no space after R") : 0;
	(check != 2) ? ft_error("wrong number of params") : 0;
	HT = (*height > 1440) ? 1440 : *height;
	WH = (*width > 2560) ? 2560 : *width;
}

int		ft_intlen(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		i++;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	ft_north(t_mapdata *map, char *line)
{
	static int	i = -1;

	while (line[++i])
	{
		if (line[i] == 'N' && line[i + 1] == 'O' &&
			line[i + 2] != ' ')
			ft_error("Something is wrong with the path NO");
		if (line[i] == '.')
		{
			NO = ft_substr(line, i, ft_strlen(line + i));
			ft_lstadd_front(&g_mylist, ft_lstnew(NO));
			MCHECK++;
			break ;
		}
	}
}

void	ft_south(t_mapdata *map, char *line)
{
	static int i = -1;

	while (line[++i])
	{
		if (line[i] == 'S' && line[i + 1] == 'O' &&
			line[i + 2] != ' ')
			ft_error("Something is wrong with the path SO");
		if (line[i] == '.')
		{
			SO = ft_substr(line, i, ft_strlen(line + i));
			ft_lstadd_front(&g_mylist, ft_lstnew(SO));
			MCHECK++;
			break ;
		}
	}
}

void	ft_west(t_mapdata *map, char *line)
{
	static int i = -1;

	while (line[++i])
	{
		if (line[i] == 'W' && line[i + 1] == 'E' &&
			line[i + 2] != ' ')
			ft_error("Something is wrong with the path WE");
		if (line[i] == '.')
		{
			WE = ft_substr(line, i, ft_strlen(line + i));
			ft_lstadd_front(&g_mylist, ft_lstnew(WE));
			MCHECK++;
			break ;
		}
	}
}
