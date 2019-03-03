/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:23:51 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/02 18:28:26 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 1500
# define WIN_HEIGHT 1000

# include <math.h>
# include "../miniLibX/mlx.h"
# include "../libft/libft.h"

typedef struct	s_cam
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	int			scale;
	double		**matrix;
}				t_cam;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_vector;

typedef struct	s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	t_vector	**vectors;
}				t_map;

typedef struct	s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}				t_mouse;

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}				t_image;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_image		*image;
	t_map		*map;
	t_cam		*cam;
	t_mouse		*mouse;
	double		**zbuf;
}				t_mlx;

typedef struct	s_line
{
	t_vector	start;
	t_vector	stop;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}				t_line;

int				event_mousemove(int x, int y, t_mlx *mlx);
int				event_mousedown(int button, int x, int y, t_mlx *mlx);
int				event_mouseup(int button, int x, int y, t_mlx *mlx);
int				event_esc(int key, t_mlx *mlx);
int				read_fdf(int fd, t_map **map);
t_vector		*get_vector(int x, int y, char *str);
t_map			*get_map(int width, int height);
t_mlx			*init(char *title);
void			render(t_mlx *mlx);
t_vector		rotate(t_vector p, t_cam *r);
t_vector		vector_at(t_map *map, int x, int y);
t_vector		set_vector(t_vector p, t_mlx *mlx);
void			image_set_pxl(t_image *image, int x, int y, int color);
void			clear_image(t_image *image);
int				lineclip(t_vector *p1, t_vector *p2);
t_image			*new_image(t_mlx *mlx);
t_image			*del_image(t_mlx *mlx, t_image *img);
void			fill_gradient(t_map *m);
int				gradient(int c1, int c2, double p);
int				height_color(int c1, int c2, double p);
#endif
