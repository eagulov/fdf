/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:45:11 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/22 15:07:52 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void    trans_coords(int z, t_point *pnt, t_map *map, int i)
{
    pnt[i].x = ((map->x_now - map->y_now) + map->step_x) * cos(0.523599);
    pnt[i].y = -(z * 3) + (map->x_now + map->y_now) * sin(0.523599);
    map->x_now = map->x_now + map->step_x;
	// if (i > 0)
		// draw_x(pnt, i, map);
    // mlx_pixel_put(map->mlx_ptr, map->win_ptr, pnt[i].x, pnt[i].y, 0xff0000);
}

void    coords(t_point *pnt, t_map *map, char *line)
{
    int     i;
    int     p;
    char    **massiv_z;

    p = 0;
    i = 0;
    massiv_z = ft_strsplit(line, ' ');
    while (p < map->width)
    {
        trans_coords(ft_atoi(massiv_z[p]), pnt, map, i);
        i++;
        p++;
    }
}

void    map_init(t_map *map, int x, int y)
{
    map->height = y;
    map->width = x;
    map->total = x * y;
    map->step_x = 750 / x;
    map->step_y = 750 / y;
    map->x_now = 200;
	map->y_now = 200;
}

void	read_map(t_map *map, int fd)
{
    char	*line;
    int     x;
    int     y;
    t_point *pnt;

    x = 0;
    y = 0;
    line = NULL;
    while((get_next_line(fd, &line) == 1))
    {
        x = my_count_words(line, ' ');
        y++;
    }
    map_init(map, x, y);
    pnt = (t_point *)malloc(sizeof(t_point) * map->total);
    while (get_next_line(fd, &line) == 1)
        coords(pnt, map, line);
    // connect_line(pnt, map);
    //free(pnt);
    //free(line);
    //close(fd);
}