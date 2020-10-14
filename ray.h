#ifndef RAY_H
# define RAY_H

typedef struct	s_lista
{
    double  dx;
    double  dy;
    double  x;
    double  y;
    double  faceup;
    double  facedown;
    double  faceright;
    double  faceleft;
    double  arc;
    double  hitv;
    double  hith;
    double  wallx;
    double  wallvx;
    double  wallhx;
    double  wally;
    double  wallvy;
    double  wallhy;
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

void	init(t_horizontal *it);
void    ft_facewhere(t_horizontal *it);
double	ft_horizontal(t_mapdata *map, t_horizontal *it);
double	ft_vertical(t_mapdata *map, t_horizontal *it);
double	colmdist(t_mapdata *map, t_horizontal *it);

#endif