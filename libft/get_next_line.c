/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:44:41 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/07 18:39:57 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	new_line(char **text, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (text[fd][len] != '\n' && text[fd][len] != '\0')
		len++;
	if (text[fd][len] == '\n')
	{
		*line = ft_strsub(text[fd], 0, len);
		tmp = ft_strdup(text[fd] + len + 1);
		free(text[fd]);
		text[fd] = tmp;
		if (text[fd][0] == '\0')
			ft_strdel(&text[fd]);
	}
	else if (text[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(text[fd]);
		ft_strdel(&text[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*text[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (!line || fd < 0 || BUFF_SIZE < 1 || fd > OPEN_MAX)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (text[fd] == NULL)
			text[fd] = ft_strnew(0);
		tmp = ft_strjoin(text[fd], buf);
		free(text[fd]);
		text[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (text[fd] == NULL || text[fd][0] == '\0'))
		return (0);
	return (new_line(text, line, fd, ret));
}
