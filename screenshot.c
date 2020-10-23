/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:31:25 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/22 17:51:39 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

static	int		create_file(char *file_name)
{
	int	fd;

	if (!((fd = open(file_name, O_WRONLY | O_CREAT |
	O_TRUNC, S_IRUSR | S_IWUSR)) > 0))
	{
		ft_error("Screenshot problem");
	}
	return (fd);
}

static void		head_make(t_bmp_file *info_bmp_file, t_mapdata *map)
{
	info_bmp_file->bftype[0] = 0x42;
	info_bmp_file->bftype[1] = 0x4D;
	info_bmp_file->bfsize = (WH * HT * 4) + 54;
	info_bmp_file->bfreserved1 = 0x00000000;
	info_bmp_file->bfoffbits = 0x36;
	info_bmp_file->bisize = 40;
	info_bmp_file->biwidth = WH;
	info_bmp_file->biheight = -HT;
	info_bmp_file->biplanes = 1;
	info_bmp_file->bibitcount = 32;
	info_bmp_file->bicompression = 0;
	info_bmp_file->bisizeimage = (WH * HT * 4);
	info_bmp_file->bixpermeter = 2835;
	info_bmp_file->biypermeter = 2835;
	info_bmp_file->biclrused = 0;
	info_bmp_file->biclrimportant = 0;
}

static void		head_write(int fd, t_bmp_file info_bmp_file)
{
	int			r;

	r = 0;
	r = write(fd, &info_bmp_file.bftype, 2);
	r = write(fd, &info_bmp_file.bfsize, 4);
	r = write(fd, &info_bmp_file.bfreserved1, 4);
	r = write(fd, &info_bmp_file.bfoffbits, 4);
	r = write(fd, &info_bmp_file.bisize, 4);
	r = write(fd, &info_bmp_file.biwidth, 4);
	r = write(fd, &info_bmp_file.biheight, 4);
	r = write(fd, &info_bmp_file.biplanes, 2);
	r = write(fd, &info_bmp_file.bibitcount, 2);
	r = write(fd, &info_bmp_file.bicompression, 4);
	r = write(fd, &info_bmp_file.bisizeimage, 4);
	r = write(fd, &info_bmp_file.bixpermeter, 4);
	r = write(fd, &info_bmp_file.biypermeter, 4);
	r = write(fd, &info_bmp_file.biclrused, 4);
	r = write(fd, &info_bmp_file.biclrimportant, 4);
	(void)r;
}

static void		file_write(int fd, int imagesize, t_mapdata *map)
{
	char		*pixel_array;
	int			i;
	int			j;

	if (!(pixel_array = malloc(sizeof(char) * imagesize)))
		ft_error("Error screenshot");
	i = 0;
	j = 0;
	imagesize /= 4;
	while (i < imagesize)
	{
		pixel_array[j++] = DATA[i] & 255;
		pixel_array[j++] = (DATA[i] & 255 << 8) >> 8;
		pixel_array[j++] = (DATA[i] & 255 << 16) >> 16;
		pixel_array[j++] = 0;
		i++;
	}
	j = write(fd, pixel_array, imagesize *= 4);
	free(pixel_array);
}

void			save_bmp(t_mapdata *map)
{
	t_bmp_file	info_bmp_file;
	int			fd;

	ft_bzero(&info_bmp_file, sizeof(t_bmp_file));
	fd = create_file("screenshot.bmp");
	head_make(&info_bmp_file, map);
	head_write(fd, info_bmp_file);
	file_write(fd, info_bmp_file.bisizeimage, map);
	close(fd);
	(void)info_bmp_file;
}
