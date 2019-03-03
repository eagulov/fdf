/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:44:04 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/02 17:44:07 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_vector rotate(t_vector p, t_cam *r)
{
	t_vector v;
	double x;
	double y;
	double z;

	x = p.x;
	z = p.z;
	v.x = cos(r->y) * x + sin(r->y) * z;
	v.z = -sin(r->y) * x + cos(r->y) * z;
	y = p.y;
	z = v.z;
	v.y = cos(r->x) * y - sin(r->x) * z;
	v.z = sin(r->x) * y + cos(r->x) * z;
	v.color = p.color;
	return (v);
}
