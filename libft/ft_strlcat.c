/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:42:21 by eagulov           #+#    #+#             */
/*   Updated: 2018/12/17 22:50:08 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (dst[i] && i < dstsize)
		i++;
	while ((src[k]) && ((i + k + 1) < dstsize))
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i != dstsize)
		dst[i + k] = '\0';
	return (i + ft_strlen(src));
}
