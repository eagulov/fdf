/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:24:34 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/02 18:41:33 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

// int		exit_response(char *reason)
// {
// 	ft_putendl(reason);
// 	return (1);
// }

int main(int ac, char **av)
{
	t_map *map;
	t_mlx *mlx;
	int fd;

	// if (ac < 2)
	// 	return (exit_response("error: you didn't point to a file"));
	if (ac != 2)
		write(1, "Usage: ./fdf 'Expected file name'\n", 35);
	// fd = open(av[1], O_RDONLY);
	// if (fd < 0 || !read_fdf(fd, &map))
	// return (exit_response("error: fdf is wrong"));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		write(1, "Error: 'fdf is wrong'\n", 23);
	read_fdf(fd, &map);
	if ((mlx = init(ft_strjoin("FdF - ", av[1]))) == NULL)
		write(1, "Error: 'mlx couldn't init'\n", 28);
	// return (exit_response("error: mlx couldn't init"));
	mlx->map = map;
	render(mlx);
	mlx_key_hook(mlx->window, event_esc, mlx);
	mlx_hook(mlx->window, 4, 0, event_mousedown, mlx);
	mlx_hook(mlx->window, 5, 0, event_mouseup, mlx);
	mlx_hook(mlx->window, 6, 0, event_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
