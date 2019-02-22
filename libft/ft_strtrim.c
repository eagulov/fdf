/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:37:18 by eagulov           #+#    #+#             */
/*   Updated: 2018/12/17 23:18:08 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	char	*str;

	if (s == NULL)
		return (NULL);
	n = ft_strlen(s);
	while (s[n - 1] == ' ' || s[n - 1] == '\n' || s[n - 1] == '\t')
		n--;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		n--;
	}
	n = (n <= 0) ? 0 : n;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	s += i;
	i = -1;
	while (++i < n)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
