/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:44:18 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/06 10:55:52 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_vectr	rotate(t_vectr p, t_view *r)
{
	t_vectr	v;
	double	x;
	double	y;
	double	z;

	x = p.x;
	z = p.z;
	v.x = cos(r->y) * x + sin(r->y) * -z;
	v.z = -sin(r->y) * x + cos(r->y) * -z;
	y = p.y;
	z = v.z;
	v.y = cos(r->x) * y - sin(r->x) * z;
	v.z = sin(r->x) * y + cos(r->x) * -z;
	v.color = p.color;
	return (v);
}

void	fill_gradient(t_map *m)
{
	t_vectr v;
	t_vectr *cur;

	v.y = 0;
	while (v.y < m->height)
	{
		v.x = 0;
		while (v.x < m->width)
		{
			cur = m->vectors[(int)v.y * m->width + (int)v.x];
			cur->color = height_color(0x00F7F7, 0xFF00FF, my_ilerp(cur->z,
												m->depth_min, m->depth_max));
			v.x++;
		}
		v.y++;
	}
}

t_vectr	set_vector(t_vectr v, t_mlx *mlx)
{
	v.x -= (double)(mlx->map->width - 1) / 4.0f;
	v.y -= (double)(mlx->map->height - 1) / 4.0f;
	v.z -= (double)(mlx->map->depth_min + mlx->map->depth_max) / 4.0f;
	v = rotate(v, mlx->view);
	v.x *= mlx->view->scale;
	v.y *= mlx->view->scale;
	v.x += mlx->view->set_x;
	v.y += mlx->view->set_y;
	return (v);
}

t_vectr	*get_vector(int x, int y, char *str)
{
	t_vectr *v;

	v = ft_memalloc(sizeof(t_vectr));
	if (v == NULL)
		return (NULL);
	v->x = (double)x;
	v->y = (double)y;
	v->z = (double)ft_atoi(str);
	v->color = 0x7F0101;
	return (v);
}

t_vectr	vector_at(t_map *map, int x, int y)
{
	return (*map->vectors[y * map->width + x]);
}
