/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:24:32 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/06 11:24:42 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		mix_hex(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

int		gradient(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = mix_hex((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = mix_hex((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = mix_hex(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

int		height_color(int c1, int c2, double p)
{
	if (p >= 0.99)
	{
		return (0xFFFFFF);
	}
	else
		return (gradient(c1, c2, p));
}
