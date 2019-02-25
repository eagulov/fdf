/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:39:04 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/24 17:29:18 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_map
{
	int		sx;
	int		sy;
	int		d;
	int		d1;
	int		d2;
	int		i;
	int		dx;
	int		dy;
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	int		total;
	int		step_x;
	int		step_y;
	int		x_now;
	int		y_now;
}				t_map;

void    trans_coords(int z, t_point *pnt, t_map *map, int i);
void    coords_row(t_point *pnt, t_map *map, char *line, int i);
void    init_map(t_map *map, int x, int y);
void	keep_draw(t_point *pnt, int count, t_map *map);
void	draw_y(t_point *pnt, int count, t_map *map);
void    get_map_info(t_map *map, int fd);
t_point	*main_helper(char *file, t_map *map);
int		press(int key, void *param);
void    connect_x(t_point *pnt, t_map *map);
void	connect_y(t_point *pnt, t_map *map);

#endif