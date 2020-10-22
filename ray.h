/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:18:10 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/22 10:09:07 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct	s_lista
{
	double	dx;
	double	dy;
	double	x;
	double	y;
	double	faceup;
	double	facedown;
	double	faceright;
	double	faceleft;
	double	arc;
	int		hitv;
	int		hith;
	double	wallx;
	double	wally;
	int		wallvy;
	int		wallvx;
	int		wallhx;
	int		wallhy;
	int		textnum;
	int		*texturedata[4];
	void	*textureimage;
}				t_horizontal;

# define FCEUP it->faceup
# define FCEDOWN it->facedown
# define FCELEFT it->faceleft
# define FCERIGHT it->faceright
# define DY it->dy
# define Y it->y
# define WALLY it->wally
# define WALLVY it->wallvy
# define WALLHY it->wallhy
# define DX it->dx
# define X it->x
# define WALLVX it->wallvx
# define WALLHX it->wallhx
# define WALLX it->wallx
# define ARC it->arc
# define HH it->hith
# define HV it->hitv
# define TXTIMG it->textureimage
# define TXTDATA it->texturedata
# define TXTNUM it->textnum

void			init(t_horizontal *it);
void			ft_facewhere(t_horizontal *it);
void			generete_wall(t_mapdata *map, t_horizontal *it,
	int b, double theone);
void			rayfacing(t_horizontal *it);
void			ft_helpdrawasquare(t_mapdata *map);
void			picktxt(t_horizontal *it);
void			ft_drawaplayer(t_mapdata *map);
void			texture(t_horizontal *it, t_mapdata *map);
double			ft_horizontal(t_mapdata *map, t_horizontal *it);
double			ft_vertical(t_mapdata *map, t_horizontal *it);
double			colmdist(t_mapdata *map, t_horizontal *it);

#endif
