/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:43:31 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/06 11:27:47 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int	clean_up(t_list **lst, t_map **map)
{
	t_list *next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_memdel(&(*lst)->content);
		ft_memdel((void **)lst);
		*lst = next;
	}
	if (map && *map)
	{
		ft_memdel((void **)&(*map)->vectors);
		ft_memdel((void **)map);
	}
	return (0);
}

static int	get_lines(int fd, t_list **lst)
{
	t_list	*tmp;
	int		expected;
	char	*line;
	int		ret;

	expected = -1;
	while ((ret = get_next_line(fd, &line)))
	{
		if (expected == -1)
			expected = (int)my_count_words(line, ' ');
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		// if ((tmp) == NULL)
		// 	return (clean_up(lst, NULL));
		my_lstadd_end(lst, tmp);
		// if (expected != (int)my_count_words(line, ' '))
		// 	return (clean_up(lst, NULL));
		ft_strdel(&line);
	}
	// if (expected == -1 || ret == -1)
	// 	return (clean_up(lst, NULL));
	return (1);
}

void		how_depth(t_map *m)
{
	int		min;
	int		max;
	t_vectr	v;
	t_vectr	cur;

	min = INT_MAX;
	max = INT_MIN;
	v.y = 0;
	while (v.y < m->height)
	{
		v.x = 0;
		while (v.x < m->width)
		{
			cur = *m->vectors[(int)v.y * m->width + (int)v.x];
			if (cur.z < min)
				min = cur.z;
			if (cur.z > max)
				max = cur.z;
			v.x++;
		}
		v.y++;
	}
	m->depth_min = min;
	m->depth_max = max;
}

static int	fill_map(t_map **m, t_list *list)
{
	t_list	*lst;
	char	**split;
	int		x;
	int		y;

	lst = list;
	y = 0;
	while (y < (*m)->height)
	{
		x = 0;
		if ((split = ft_strsplit(lst->content, ' ')) == NULL)
			return (clean_up(&list, m));
		while (x < (*m)->width)
		{
			(*m)->vectors[y * (*m)->width + x] = get_vector(x, y, split[x]);
			x++;
		}
		my_splitdel(&split);
		lst = lst->next;
		y++;
	}
	how_depth(*m);
	fill_gradient(*m);
	clean_up(&list, NULL);
	return (1);
}

int			read_fdf(int fd, t_map **m)
{
	t_list *lst;

	lst = NULL;
	if (!(get_lines(fd, &lst)))
		return (0);
	*m = get_map(my_count_words(lst->content, ' '), my_lstcount(lst));
	if (*m == NULL)
		return (clean_up(&lst, m));
	return (fill_map(m, lst));
}
