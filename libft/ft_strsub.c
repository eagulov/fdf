/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 18:05:07 by eagulov           #+#    #+#             */
/*   Updated: 2018/12/18 18:01:46 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*f;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	f = (char *)malloc(sizeof(char) * (len + 1));
	if (!f)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		f[i++] = s[start++];
	}
	f[i] = '\0';
	return (f);
}
