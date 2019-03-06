/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:22:40 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/05 23:28:48 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	move_down(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	if (y < 0)
		return (0);
	mlx->mouse->isdown |= 1 << button;
	return (0);
}

int	move_up(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse->isdown &= ~(1 << button);
	return (0);
}

int	move_mouse(int x, int y, t_mlx *mlx)
{
	mlx->mouse->prev_x = mlx->mouse->x;
	mlx->mouse->prev_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->isdown & (1 << 1) && mlx->mouse->isdown & (1 << 2))
	{
		mlx->view->set_x += (x - mlx->mouse->prev_x);
		mlx->view->set_y += (y - mlx->mouse->prev_y);
	}
	else if (mlx->mouse->isdown & (1 << 1))
	{
		mlx->view->x += (mlx->mouse->prev_y - y) / 200.0f;
		mlx->view->y -= (mlx->mouse->prev_x - x) / 200.0f;
	}
	else if (mlx->mouse->isdown & (1 << 2))
	{
		mlx->view->scale += (mlx->mouse->prev_y - y) / 10.0f + 0.5f;
		if (mlx->view->scale < 1)
			mlx->view->scale = 1;
	}
	if (mlx->mouse->isdown)
		perform(mlx);
	return (0);
}
