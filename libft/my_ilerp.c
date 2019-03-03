/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ilerp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:30:23 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/02 15:32:17 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	my_ilerp(double val, double first, double second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}
