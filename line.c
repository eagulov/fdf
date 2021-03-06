/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:43:06 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/05 23:27:20 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		area(int x, int y)
{
	int c;

	c = 0;
	if (y >= WIN_HEIGHT)
		c |= 1;
	else if (y < 0)
		c |= 2;
	if (x >= WIN_WIDTH)
		c |= 4;
	else if (x < 0)
		c |= 8;
	return (c);
}

void	clip_xy(t_vectr *v, t_vectr *p1, t_vectr *p2, int rout)
{
	if (rout & 1)
	{
		v->x = p1->x + (p2->x - p1->x) * (WIN_HEIGHT - p1->y) / (p2->y - p1->y);
		v->y = WIN_HEIGHT - 1;
	}
	else if (rout & 2)
	{
		v->x = p1->x + (p2->x - p1->x) * -p1->y / (p2->y - p1->y);
		v->y = 0;
	}
	else if (rout & 4)
	{
		v->x = WIN_WIDTH - 1;
		v->y = p1->y + (p2->y - p1->y) * (WIN_WIDTH - p1->x) / (p2->x - p1->x);
	}
	else
	{
		v->x = 0;
		v->y = p1->y + (p2->y - p1->y) * -p1->x / (p2->x - p1->x);
	}
}

int		clip_line(t_vectr *p1, t_vectr *p2)
{
	t_vectr	v;
	int		r1;
	int		r2;
	int		rout;

	r1 = area(p1->x, p1->y);
	r2 = area(p2->x, p2->y);
	while (!(!(r1 | r2) || (r1 & r2)))
	{
		rout = r1 ? r1 : r2;
		clip_xy(&v, p1, p2, rout);
		if (rout == r1)
		{
			p1->x = v.x;
			p1->y = v.y;
			r1 = area(p1->x, p1->y);
		}
		else
		{
			p2->x = v.x;
			p2->y = v.y;
			r2 = area(p2->x, p2->y);
		}
	}
	return (!(r1 | r2));
}
