/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:44:41 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/21 20:42:51 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_read(int fd, char **text)
{
	int			len;
	char		*tmp;
	char		buf[BUFF_SIZE + 1];

	ft_bzero(buf, BUFF_SIZE + 1);
	len = read(fd, buf, BUFF_SIZE);
	if (len == -1)
		return (-1);
	buf[len] = '\0';
	tmp = *text;
	*text = ft_strjoin(*text, buf);
	if (*tmp != 0)
		free(tmp);
	return (len);
}

int			ready(char **text, char **line, char *tmp)
{
	int		check;
	char	*new;

	check = 0;
	if (*tmp == '\n')
		check = 1;
	*tmp = 0;
	*line = ft_strjoin("", *text);
	if (!check)
	{
		if (!(ft_strlen(*text)))
			return (0);
		else
		{
			*text = "\0";
			return (1);
		}
	}
	new = *text;
	*text = ft_strjoin(tmp + 1, "");
	free(new);
	return (check);
}

int			get_next_line(const int fd, char **line)
{
	int			len;
	char		*tmp;
	static char	*text[OPEN_MAX];

	if (!line || fd < 0 || BUFF_SIZE < 1 || fd > OPEN_MAX)
		return (-1);
	if (!text[fd])
		text[fd] = "";
	len = BUFF_SIZE;
	while (line)
	{
		tmp = text[fd];
		while (*tmp || len < BUFF_SIZE)
		{
			if (*tmp == '\n' || !(*tmp))
				return (ready(&text[fd], line, tmp));
			tmp++;
		}
		len = ft_read(fd, &text[fd]);
		if (len == -1)
			return (-1);
	}
	return (1);
}
