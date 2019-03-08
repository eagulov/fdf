/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:24:34 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/08 12:28:13 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	press_button(int key, t_mlx *param)
{
	(void)param;
	if (key == 53)
		exit(1);
	if (key == 76 || key == 36)
	{
		param->view->scale += 5;
	}
	if (key == 49)
	{
		param->view->scale -= 5;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;
	int		fd;

	if ((argc != 2) || (fd = open(argv[1], O_RDONLY) < 0))
	{
		write(1, "'Expected file name or something wrong with ./fdf'\n", 52);
		exit(0);
	}
	read_fdf(fd, &map);
	if ((mlx = init(argv[1])) == NULL)
	{
		write(1, "Error: 'mlx couldn't initialize'\n", 34);
		exit(0);
	}
	mlx->map = map;
	perform(mlx);
	mlx_key_hook(mlx->window, press_button, mlx);
	mlx_hook(mlx->window, 4, 0, move_down, mlx);
	mlx_hook(mlx->window, 5, 0, move_up, mlx);
	mlx_hook(mlx->window, 6, 0, move_mouse, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
