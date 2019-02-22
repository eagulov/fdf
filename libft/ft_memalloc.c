/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:26:03 by eagulov           #+#    #+#             */
/*   Updated: 2018/12/17 15:09:29 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;
	char	*temp;

	str = malloc(size);
	if (!str)
		return (NULL);
	if (size > 0)
	{
		temp = str;
		while (size)
		{
			*temp++ = (unsigned char)0;
			size--;
		}
	}
	return (str);
}
