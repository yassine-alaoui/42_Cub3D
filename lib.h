/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 00:32:04 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/28 19:09:58 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H

# define LIB_H

# include <math.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_prite
{
	float	x;
	float	x_off;
	float	y;
	float	y_off;
	float	dist;
	float	size;
	int		width;
	int		height;
	int		*sdata;
	int		ditch;
	int		ditch1;
	void	*simg;
}				t_sprite;

typedef struct	s_list
{
	int		width;
	int		height;
	int		floor[3];
	int		keys0;
	int		keyv0;
	int		keys1;
	int		keyv1;
	int		view;
	int		ceeling[3];
	int		mapcheck;
	int		size_line;
	int		lol;
	int		endian;
	int		*mlxdata;
	int		nhexfloor;
	int		nhexceeling;
	int		pp;
	int		up;
	int		down;
	int		right;
	int		left;
	int		*raydist;
	int		screen;
	float	playerx;
	float	playery;
	float	wdis;
	float	drota;
	float	dwdx;
	float	dwdy;
	float	angle;
	void	*mlximage;
	void	*mlx;
	char	*maponestr;
	char	hexfloor[8];
	char	hexceeling[8];
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	char	**map2d;
	t_sprite	*sprites;
}				t_mapdata;

typedef struct	s_lst
{
	void			*content;
	struct s_lst	*next;
}				t_list;

# define WH map->width
# define HT map->height
# define NO map->north
# define SO map->south
# define WE map->west
# define EA map->east
# define S map->sprite
# define F map->floor
# define C map->ceeling
# define PP map->pp
# define MAP0 map->maponestr
# define MAP2D map->map2d
# define MCHECK map->mapcheck
# define PX map->playerx
# define PY map->playery
# define IMAGE map->mlximage
# define DATA map->mlxdata
# define ENDIAN map->endian
# define SIZELINE map->size_line
# define MLX map->mlx
# define LOL map->lol
# define ANGLE map->angle
# define KEY_0 map->keyv0
# define KEY_1 map->keyv1
# define KEY_S0 map->keys0
# define KEY_S1 map->keys1
# define LEFT 124
# define RIGHT 123
# define UP 13
# define DOWN 1
# define DRT map->drota
# define DWX map->dwdx
# define DWY map->dwdy
# define DWD map->wdis
# define VIEW map->view
# define CEELING map->hexceeling
# define HEXC map->nhexceeling
# define HEXF map->nhexfloor
# define FLOOR map->hexfloor
# define FUP map->up
# define FDOWN map->down
# define FRIGHT map->right
# define FLEFT map->left
# define RAYDIST map->raydist
# define SCREEN map->screen
# define SPRITES map->sprites

# define RAD(x) (x * (M_PI / 180))
# define DEG(x) ((180 / M_PI) * x)

void			ft_init(t_mapdata *map);
void			ft_error(char *s);
void			ft_intro(int fd, t_mapdata *map);
void			ft_readno(int fd, t_mapdata *map);
void			ft_north(t_mapdata *map, char *line);
void			ft_south(t_mapdata *map, char *line);
void			ft_west(t_mapdata *map, char *line);
void			ft_east(t_mapdata *map, char *line);
void			ft_sprite(t_mapdata *map, char *line);
void			skipspace(char **line);
void			ft_floor(t_mapdata *map, char *line);
void			ft_ceeling(t_mapdata *map, char *line);
void			ft_fetch(char *line, int *height, int *width, t_mapdata *map);
void			ft_drawasquare(int a, int b, t_mapdata *map);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst);
void			ft_matrix(t_mapdata *map, char *line);
void			ft_joindouble(t_mapdata *map);
void			treatthatmap(t_mapdata *map);
void			ft_read(int fd, t_mapdata *map);
void			ft_helpdrawasquare2(t_mapdata *map);
void			ft_bzero(void *s, size_t n);
void			ft_fhexa(int nb, t_mapdata *map);
void			ft_chexa(int nb, t_mapdata *map);
void			to_sprite(t_mapdata *map, int m);
void			hex(int hex);
void			*g_mlx_win;
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				loop_me(t_mapdata *map);
int				ft_fill(char **last, int fd);
int				get_next_line(int fd, char **line);
int				ft_intlen(int i);
int				ft_isdigit(int c);
int				ft_conds(int fd, char **l);
int				ft_free(char *fr, int k);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				helpread(char *line, t_mapdata *map);
int				count_words(const char *str, char c);
int				ft_iswall(t_mapdata *map);
int				g_tiles;
int				g_rows;
size_t			ft_strlen(const char *s);
char			*ft_strtrim(char *s1, char const *set);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *dst, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char const *s, char c);
float			sean(t_mapdata *map);
t_list			*ft_lstnew(void *content);
t_list			*g_mylist;

#endif
