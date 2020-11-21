/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 23:00:47 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/11/21 20:39:59 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_fetch(char *line, t_mapdata *map)
{
	static int	i = 0;
	static int	cond1 = 1;
	static int	cond2 = 1;
	static int	check = 0;

	while (line[i++] != '\0')
	{
		(ft_isalpha(line[i])) ? ft_error("there are some abnormal chars") : 0;
		if (ft_isdigit(line[i]) && cond1 && (check += 1))
		{
			(WH = ft_atoi(line + i)) && (cond1 -= cond1);
			i += ft_intlen(WH);
		}
		if (ft_isdigit(line[i]) && !cond1 && cond2 && (check += 1))
		{
			HT = ft_atoi(line + i);
			i += ft_intlen(HT);
		}
		(ft_isdigit(line[i]) && !cond1 && !cond2) ? check++ : 0;
	}
	(!(line[1] == ' ')) ? ft_error("no space after R") : 0;
	(check != 2) ? ft_error("wrong number of R params") : 0;
	fix_res(map);
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
	static int	i = 1;

	while (line[++i])
	{
		if (line[i] == '.' || ft_isalpha(line[i]))
		{
			NO = ft_substr(line, i, ft_strlen(line));
			ft_lstadd_front(&g_mylist, ft_lstnew(NO));
			MCHECK++;
			break ;
		}
	}
}

void	ft_south(t_mapdata *map, char *line)
{
	static int i = 1;

	while (line[++i])
	{
		if (line[i] == '.' || ft_isalpha(line[i]))
		{
			SO = ft_substr(line, i, ft_strlen(line));
			ft_lstadd_front(&g_mylist, ft_lstnew(SO));
			MCHECK++;
			break ;
		}
	}
}

void	ft_west(t_mapdata *map, char *line)
{
	static int i = 1;

	while (line[++i])
	{
		if (line[i] == '.' || ft_isalpha(line[i]))
		{
			WE = ft_substr(line, i, ft_strlen(line));
			ft_lstadd_front(&g_mylist, ft_lstnew(WE));
			MCHECK++;
			break ;
		}
	}
}
