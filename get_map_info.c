/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:42:05 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/24 16:53:05 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void    init_map(t_map *map, int x, int y)
{
    map->height = y;
    map->width = x;
    map->total = x * y;
    map->step_x = 500 / x;
    map->step_y = 500 / y;
    map->x_now = 100 - map->step_x;
	map->y_now = 100;
}

void    get_map_info(t_map *map, int fd)
{
    char    *line;
    int     y;
    int     x;

    line = NULL;
    y = 0;
    while (get_next_line(fd, &line) == 1)
    {
        x = my_count_words(line, ' ');
        y++;
    }
    free(line);
    close(fd);
    init_map(map, x, y);
}