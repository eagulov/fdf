/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:44:28 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/06 20:35:44 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_mlx	*mlx_exit_clean(t_mlx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->view)
		ft_memdel((void **)&mlx->view);
	if (mlx->mouse)
		ft_memdel((void **)&mlx->mouse);
	if (mlx->image)
		del_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx	*init(char *name)
{
	char	*title;
	t_mlx	*mlx;

	title = ft_strjoin("FdF - /", name);
	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT,
														title)) == NULL ||
		(mlx->view = ft_memalloc(sizeof(t_view))) == NULL ||
		(mlx->mouse = ft_memalloc(sizeof(t_mouse))) == NULL ||
		(mlx->image = new_image(mlx)) == NULL)
		return (mlx_exit_clean(mlx));
	mlx->view->x = 0.4;
	mlx->view->y = 0.4;
	mlx->view->scale = 20;
	mlx->view->set_x = WIN_WIDTH / 2.3;
	mlx->view->set_y = WIN_HEIGHT / 2.3;
	free(title);
	return (mlx);
}

t_map	*get_map(int width, int height)
{
	t_map *map;

	map = ft_memalloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = width;
	map->height = height;
	map->depth_min = 0;
	map->depth_max = 0;
	map->vectors = ft_memalloc(sizeof(t_vectr *) * width * height);
	if (map->vectors == NULL)
	{
		ft_memdel((void **)&map);
		return (NULL);
	}
	return (map);
}
