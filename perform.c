/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:43:55 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/06 11:25:37 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		calc_point(t_mlx *mlx, t_line *l, t_vectr *p1, t_vectr *p2)
{
	double prcnt;

	if (p1->x < 0 || p1->x >= WIN_WIDTH || p1->y < 0 || p1->y >= WIN_HEIGHT
		|| p2->x < 0 || p2->x >= WIN_WIDTH || p2->y < 0 || p2->y >= WIN_HEIGHT)
		return (1);
	prcnt = (l->dx > l->dy ? my_ilerp((int)p1->x, (int)l->start.x,
	(int)l->stop.x) : my_ilerp((int)p1->y, (int)l->start.y, (int)l->stop.y));
	image_set_pxl(mlx->image, (int)p1->x, (int)p1->y, height_color(p1->color,
															p2->color, prcnt));
	l->err2 = l->err;
	if (l->err2 > -l->dx)
	{
		l->err -= l->dy;
		p1->x += l->sx;
	}
	if (l->err2 < l->dy)
	{
		l->err += l->dx;
		p1->y += l->sy;
	}
	return (0);
}

void	line(t_mlx *mlx, t_vectr p1, t_vectr p2)
{
	t_line line;

	p1.x = (int)p1.x;
	p2.x = (int)p2.x;
	p1.y = (int)p1.y;
	p2.y = (int)p2.y;
	line.start = p1;
	line.stop = p2;
	if (!clip_line(&p1, &p2))
		return ;
	line.dx = (int)my_abs((int)p2.x - (int)p1.x);
	line.sx = (int)p1.x < (int)p2.x ? 1 : -1;
	line.dy = (int)my_abs((int)p2.y - (int)p1.y);
	line.sy = (int)p1.y < (int)p2.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y))
		if (calc_point(mlx, &line, &p1, &p2))
			break ;
}

void	perform(t_mlx *mlx)
{
	int		x;
	int		y;
	t_vectr	v;
	t_map	*map;

	map = mlx->map;
	clear_image(mlx->image);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			v = set_vector(vector_at(map, x, y), mlx);
			if (x + 1 < map->width)
				line(mlx, v, set_vector(vector_at(map, x + 1, y), mlx));
			if (y + 1 < map->height)
				line(mlx, v, set_vector(vector_at(map, x, y + 1), mlx));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
