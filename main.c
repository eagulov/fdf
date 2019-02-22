/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:40:27 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/22 09:30:57 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		press(int key, void *param)
{
	(void)param;
	if (key == 53)
	{
		exit(1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	
	// fd = open(argv[1], O_RDONLY);
	if (argc < 2)
		write(1, "Usage: ./fdf 'Expected file name'\n", 35);
	else if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (-1);
	else if (argc == 2)
	{
		map = (t_map *)malloc(sizeof(t_map));
		map->mlx_ptr = mlx_init();
		map->win_ptr = mlx_new_window(map->mlx_ptr, 1500, 1500, "yo");
		read_map(map, fd);
		// mlx_pixel_put(map->mlx_ptr, map->win_ptr, 500, 750, 0xe830a7);
		mlx_key_hook(map->win_ptr, press, (void *)0);
		mlx_loop(map->mlx_ptr);
	}
	else
		return (-1);
}