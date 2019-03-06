/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:23:51 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/06 10:59:11 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 1600
# define WIN_HEIGHT 1000

# include <math.h>
# include "../miniLibX/mlx.h"
# include "../libft/libft.h"

typedef struct	s_view
{
	double		set_x;
	double		set_y;
	double		x;
	double		y;
	int			scale;
	double		**matrix;
}				t_view;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_vectr;

typedef struct	s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	t_vectr		**vectors;
}				t_map;

typedef struct	s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
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
	t_view		*view;
	t_mouse		*mouse;
	double		**zbuf;
}				t_mlx;

typedef struct	s_line
{
	t_vectr		start;
	t_vectr		stop;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}				t_line;

void			my_lstadd_end(t_list **alst, t_list *new);
int				move_mouse(int x, int y, t_mlx *mlx);
int				move_down(int button, int x, int y, t_mlx *mlx);
int				move_up(int button, int x, int y, t_mlx *mlx);
int				scaling_hook(int k, t_view *view);
int				press_button(int key, t_mlx *param);
int				read_fdf(int fd, t_map **map);
t_vectr			*get_vector(int x, int y, char *str);
t_map			*get_map(int width, int height);
t_mlx			*init(char *title);
void			perform(t_mlx *mlx);
t_vectr			vector_at(t_map *map, int x, int y);
t_vectr			set_vector(t_vectr p, t_mlx *mlx);
void			image_set_pxl(t_image *image, int x, int y, int color);
void			clear_image(t_image *image);
int				clip_line(t_vectr *p1, t_vectr *p2);
t_image			*new_image(t_mlx *mlx);
t_image			*del_image(t_mlx *mlx, t_image *img);
void			fill_gradient(t_map *m);
int				gradient(int c1, int c2, double p);
int				height_color(int c1, int c2, double p);
#endif
