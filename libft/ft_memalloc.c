/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:26:03 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/07 11:56:31 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;
	char	*tmp;

	str = malloc(size);
	if (!str)
		return (NULL);
	if (size > 0)
	{
		tmp = str;
		while (size)
		{
			*tmp++ = (unsigned char)0;
			size--;
		}
	}
	return (str);
}
