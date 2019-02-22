/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:37:14 by eagulov           #+#    #+#             */
/*   Updated: 2018/12/17 23:01:24 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *temp;

	temp = b;
	if (len > 0)
	{
		while (len)
		{
			*temp++ = (unsigned char)c;
			len--;
		}
	}
	return (b);
}
