/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_celsius_fahrenheit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:48:00 by eagulov           #+#    #+#             */
/*   Updated: 2018/12/19 18:51:07 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	my_celsius_fahrenheit(float celsius)
{
	float fahrenheit;

	fahrenheit = (celsius * 9 / 5) + 32;
	return (fahrenheit);
}
