/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_314area.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:50:52 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/02 18:16:13 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	my_314area(float radius)
{
	float area;

	area = 3.14 * (radius * radius);
	return (area);
}
