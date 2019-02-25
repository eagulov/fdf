/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 10:54:14 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/24 18:25:13 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	keep_draw(t_point *pnt, int count, t_map *map)
{
	int y;
	int x;

	map->d = (map->dx << 1) - map->dy;
	map->d1 = map->dx << 1;
	map->d2 = (map->dx - map->dy) << 1;
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, 500 + pnt[count].x,
		200 + pnt[count].y, map->color = 0xb4354f);
	y = pnt[count].y + map->sy;
	x = pnt[count].x;
	map->i = 1;
	while (map->i <= map->dy)
	{
		if (map->d > 0)
		{
			map->d += map->d2;
			x += map->sx;
		}
		else
			map->d += map->d1;
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, 500 + x, 200 + y, map->color = 0xb4354f);
		map->i++;
		y += map->sy;
	}
}

void	draw_y(t_point *pnt, int count, t_map *map)
{
	int x;
	int y;

	map->d = (map->dy << 1) - map->dx;
	map->d1 = map->dy << 1;
	map->d2 = (map->dy - map->dx) << 1;
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, 500 + pnt[count].x,
		200 + pnt[count].y, map->color = 0xb4354f);
	y = pnt[count].y + map->sy;
	x = pnt[count].x;
	while (map->i <= map->dx)
	{
		if (map->d > 0)
		{
			map->d += map->d2;
			y += map->sy;
		}
		else
			map->d += map->d1;
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, 500 + x, 200 + y,
			map->color = 0xb4354f);
		map->i++;
		x += map->sx;
	}
}

// void    connect_x(t_point *pnt, int i, t_map *map)
// {
//     int dx;
//     int dy;
//     int x;
//     int y;

//     dx = pnt[i].x - pnt[i - 1].x;
//     dy = pnt[i].y - pnt[i - 1].y;
//     x = pnt[i - 1].x;
//     while (pnt[i].x > x)
//     {
//         y = pnt[i - 1].y + dy * (x - pnt[i - 1].x) / dx;
//         mlx_pixel_put(map->mlx_ptr, map->win_ptr, 500 + x, 200 + y, map->color = 0xb4354f);
//         x++;
//     }    
// }

void	connect_y(t_point *pnt, t_map *map)
{
    int count;
    int prev_y;

    count = 0;
    while (count < map->total)
    {
        prev_y = count - map->width;
        if (prev_y >= 0)
        {
            map->i = 1;
            map->dy = abs(pnt[prev_y].y - pnt[count].y);
	        map->dx = abs(pnt[prev_y].x - pnt[count].x);
	        map->sx = pnt[prev_y].x >= pnt[count].x ? 1 : -1;
	        map->sy = pnt[prev_y].y >= pnt[count].y ? 1 : -1;
            if (map->dy <= map->dx)
            {
                draw_y(pnt, count, map);
            }
            else
                keep_draw(pnt, count, map);
        }
        count++;
    }
}

void    connect_x(t_point *pnt, t_map *map)
{
    int dx;
    int dy;
    int x;
    int y;

    int i = 0;
    while (i < map->total)
    {
		int col = i % map->width;
		if (col > 0)
		{
			dx = pnt[i].x - pnt[i - 1].x;
    		dy = pnt[i].y - pnt[i - 1].y;
			x = pnt[i - 1].x;
			while (pnt[i].x > x)
			{
				y = pnt[i - 1].y + dy * (x - pnt[i - 1].x) / dx;
				mlx_pixel_put(map->mlx_ptr, map->win_ptr, 500 + x, 200 + y, map->color = 0xb4354f);
				x++;
			}  
		}
        i++;
    }
}