/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_splitdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:12:37 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/02 15:27:12 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_splitdel(char ***split)
{
	char	**str;
	int		i;

	i = 0;
	str = *split;
	while (*str)
	{
		ft_strdel(str);
		i++;
		str = &(*split)[i];
	}
	ft_memdel((void **)split);
	return (0);
}
