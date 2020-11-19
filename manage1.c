/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:29:30 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/11/19 12:10:58 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_east(t_mapdata *map, char *line)
{
	static int i = -1;

	while (line[++i])
	{
		if (line[i] == 'E' && line[i + 1] == 'A' &&
			line[i + 2] != ' ')
			ft_error("Something is wrong with the path EA");
		if (line[i] == '.')
		{
			EA = ft_substr(line, i, ft_strlen(line));
			ft_lstadd_front(&g_mylist, ft_lstnew(EA));
			MCHECK++;
			break ;
		}
	}
}

void	ft_sprite(t_mapdata *map, char *line)
{
	static int i = -1;

	while (line[++i])
	{
		if (line[i] == 'S' && line[i + 1] != ' ')
			ft_error("Something is wrong with the path S");
		if (line[i] == '.')
		{
			S = ft_substr(line, i, ft_strlen(line));
			ft_lstadd_front(&g_mylist, ft_lstnew(S));
			MCHECK++;
			break ;
		}
	}
}

void	ft_floor(t_mapdata *map, char *line)
{
	static int	i = 0;
	static int	j = 0;

	MCHECK++;
	if (line[i] == 'F' && line[i + 1] != ' ')
		ft_error("Something is wrong with the path F");
	while (line[i] == ' ' || (line[i - 1] != ' ' && line[i] == 'F'))
		i++;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			F[j] = ft_atoi(line + i);
			i += ft_intlen(F[j]) - 1;
			(F[j] >= 0 && F[j] <= 255) ? 0
				: ft_error("it's the wrong F number");
			j++;
		}
		(line[i] == ' ' || (line[i] == ',' && ft_isdigit(line[i + 1]) &&
			ft_isdigit(line[i - 1])) || ft_isdigit(line[i])) ? 0 :
				ft_error("not a valid F color");
		i++;
	}
	HEXF = (F[0] << 16) | (F[1] << 8) | F[2];
	(j != 3) ? ft_error("not a valid F color") : 0;
}

void	ft_ceeling(t_mapdata *map, char *line)
{
	static int	i = 0;
	static int	j = 0;

	MCHECK++;
	if (line[i] == 'C' && line[i + 1] != ' ')
		ft_error("Something is wrong with the path C");
	while (line[i] == ' ' || (line[i - 1] != ' ' && line[i] == 'C'))
		i++;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			C[j] = ft_atoi(line + i);
			i += ft_intlen(C[j]) - 1;
			(C[j] >= 0 && C[j] <= 255) ? 0
				: ft_error("it's the wrong C number");
			j++;
		}
		(line[i] == ' ' || (line[i] == ',' && ft_isdigit(line[i + 1]) &&
			ft_isdigit(line[i - 1])) || ft_isdigit(line[i])) ? 0 :
				ft_error("not a valid C color");
		i++;
	}
	HEXC = (C[0] << 16) | (C[1] << 8) | C[2];
	(j != 3) ? ft_error("not a valid C color") : 0;
}

void	ft_intro(int fd, t_mapdata *map)
{
	g_rows = 0;
	ft_lstadd_front(&g_mylist, ft_lstnew(map));
	ft_read(fd, map);
	if (MCHECK != 8)
		ft_error("something is miss stated");
	if (!MAP2DB)
		MAP2DB = ft_split(MAP0, '\n');
	g_rows = count_words(MAP0, '\n');
	if (!MAP2D)
		map_manager(map);
	ft_lstadd_front(&g_mylist, ft_lstnew(MAP0));
	ft_lstadd_front(&g_mylist, ft_lstnew((MAP2D)));
	ft_lstadd_front(&g_mylist, ft_lstnew((MAP2DB)));
	treatthatmap(map);
}
