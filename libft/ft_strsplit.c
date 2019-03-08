/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 09:48:28 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/07 18:41:53 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_length(char const *str, char c)
{
	size_t cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] != c && str[cnt])
		cnt++;
	return (cnt);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	char	**tab;

	i = 0;
	if (!s || !c)
		return ((void *)0);
	words = my_count_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		while (*s == c && *s)
			s++;
		tab[i] = (char *)malloc(sizeof(char) * (my_length(s, c) + 1));
		j = 0;
		while (*s != c && *s)
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
