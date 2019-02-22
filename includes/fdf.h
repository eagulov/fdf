/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:39:04 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/22 09:30:03 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	int		total;
	int		step_x;
	int		step_y;
	int		x_now;
	int		y_now;
}				t_map;

void	read_map(t_map *map, int fd);
int		press(int key, void *param);



#endif
