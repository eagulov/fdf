/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:37:14 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/05 21:46:26 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *tmp;

	tmp = b;
	if (len > 0)
	{
		while (len)
		{
			*tmp++ = (unsigned char)c;
			len--;
		}
	}
	return (b);
}
