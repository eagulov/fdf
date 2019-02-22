/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:07:10 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/21 19:54:46 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_count_words(const char *s, char c)
{
	int	cnt;
	int	inside;

	inside = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (inside == 1 && *s == c)
			inside = 0;
		if (inside == 0 && *s != c)
		{
			inside = 1;
			cnt++;
		}
		s++;
		ft_putstr("inf\n");
	}
	return (cnt);
}