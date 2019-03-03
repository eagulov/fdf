/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:36:26 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/02 18:14:13 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}