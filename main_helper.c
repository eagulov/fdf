/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:45:11 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/24 16:03:04 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void    trans_coords(int z, t_point *pnt, t_map *map, int i)
{
    pnt[i].x = ((map->x_now - map->y_now) + map->step_x) * cos(0.523599);
    pnt[i].y = -(z * 3) + (map->x_now + map->y_now) * sin(0.523599);
    map->x_now = map->x_now + map->step_x;
	if (i > 0)
		connect_x(pnt, i, map);
    // get_color(map, z);
    mlx_pixel_put(map->mlx_ptr, map->win_ptr, pnt[i].x, pnt[i].y, 0x49236f);
}

void    coords(t_point *pnt, t_map *map, char *line, int i)
{
    int     p;
    char    **massiv_z;

    p = 0;
    massiv_z = ft_strsplit(line, ' ');
    while (p < map->width)
    {
        trans_coords(ft_atoi(massiv_z[p]), pnt, map, i);
        p++;
        i++;
    }
    map->x_now = 100 - map->step_x;
	map->y_now = map->y_now + map->step_y;
}

void	main_helper(char *file, t_map *map, int fd)
{
    int     i;
    char	*line;
    t_point *pnt;

    line = NULL;
    i = 0;
    get_map_info(map, fd);
    pnt = (t_point *)malloc(sizeof(t_point) * map->total);
    fd = open(file, O_RDONLY);
    while (get_next_line(fd, &line) == 1)
    {
        coords(pnt, map, line, i);
    }
    close(fd);
    connect_y(pnt, map);
    free(pnt);
    free(line);
}