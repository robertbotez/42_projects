/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:17:11 by rbotez            #+#    #+#             */
/*   Updated: 2017/02/15 17:42:25 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(char *buf, char **save, char **line)
{
	char	*str;

	if ((str = ft_strchr(buf, '\n')))
	{
		*str = '\0';
		*line = ft_strjoin(*save, buf);
		free(*save);
		*save = ft_strdup(str + 1);
		str = NULL;
		free(buf);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char		*save = NULL;
	int				ret;
	char			*buf;

	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	buf = (char *)malloc(sizeof(char) * 2);
	while ((ret = read(fd, buf, 1)) > 0)
	{
		buf[ret] = '\0';
		if (ft_read(buf, &save, line))
			return (1);
		save = ft_strjoin(save, buf);
	}
	if (ret == -1)
		return (-1);
	if (save == NULL)
		return (0);
	*line = ft_strdup(save);
	free(save);
	if (ret == 0 && ft_strlen(save) > 0)
		ret = 1;
	save = NULL;
	return (ret);
}
