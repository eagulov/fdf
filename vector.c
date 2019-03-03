/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:44:18 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/02 17:44:20 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void fill_gradient(t_map *m)
{
	t_vector v;
	t_vector *cur;

	v.y = 0;
	while (v.y < m->height)
	{
		v.x = 0;
		while (v.x < m->width)
		{
			cur = m->vectors[(int)v.y * m->width + (int)v.x];
			cur->color = height_color(0x00FF00, 0x7F0101, my_ilerp(cur->z, m->depth_min, m->depth_max));
			v.x++;
		}
		v.y++;
	}
}

t_vector set_vector(t_vector v, t_mlx *mlx)
{
	v.x -= (double)(mlx->map->width - 1) / 2.0f;
	v.y -= (double)(mlx->map->height - 1) / 2.0f;
	v.z -= (double)(mlx->map->depth_min + mlx->map->depth_max) / 2.0f;
	v = rotate(v, mlx->cam);
	v.x *= mlx->cam->scale;
	v.y *= mlx->cam->scale;
	v.x += mlx->cam->offsetx;
	v.y += mlx->cam->offsety;
	return (v);
}

t_vector *get_vector(int x, int y, char *str)
{
	t_vector *v;

	v = ft_memalloc(sizeof(t_vector));
	if (v == NULL)
		return (NULL);
	v->x = (double)x;
	v->y = (double)y;
	v->z = (double)ft_atoi(str);
	v->color = 0x7F0101;
	return (v);
}

t_vector vector_at(t_map *map, int x, int y)
{
	return (*map->vectors[y * map->width + x]);
}
