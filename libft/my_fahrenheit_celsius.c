/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fahrenheit_celsius.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:18:15 by eagulov           #+#    #+#             */
/*   Updated: 2018/12/19 20:44:59 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	my_fahrenheit_celsius(float fahrenheit)
{
	float celsius;

	celsius = (fahrenheit - 32) * 5 / 9;
	return (celsius);
}
