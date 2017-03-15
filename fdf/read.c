/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:18:15 by rbotez            #+#    #+#             */
/*   Updated: 2017/03/14 15:35:09 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "includes/minilibx_macos/mlx.h"
#include <fcntl.h>

int		ft_alloc(char *av)
{
	int	len;
	int	fd;

	fd = open(av, O_RDONLY);
	len = 0;
	while (get_next_line(fd, &av))
		len++;
	return (len);
}

char	**ft_read(char *av)
{
	int		fd;
	char	**tab;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_alloc(av) + 1))))
		return (0);
	while (get_next_line(fd, &av))
	{
		tab[i] = ft_strdup(av);
		free(av);
		av = (char *)malloc(sizeof(char) * BUFF_SIZE);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int		columns(char **map, int lines)
{
	char	**split;
	int		i;
	int		j;
	int		ok;

	i = 0;
	j = 0;
	split = ft_strsplit(map[0], ' ');
	while ((ft_atoi(split[j]) == 0 && split[j] != 0) || ft_atoi(split[j]))
		j++;
	ok = j;
	i++;
	while (i < lines)
	{
		j = 0;
		split = ft_strsplit(map[i], ' ');
		while ((ft_atoi(split[j]) == 0 && split[j] != 0) || ft_atoi(split[j]))
			j++;
		if (j != ok)
		{
			exit_err();
		}
		i++;
	}
	return (ok);
}

int		**ft_convert(char **map, int lines, int col)
{
	int		**points;
	char	**split;
	int		i;
	int		j;

	if (col == 0)
		return (0);
	points = (int **)malloc(sizeof(int *) * (lines + 1));
	i = 0;
	while (i < lines)
	{
		points[i] = (int *)malloc(sizeof(int) * (col + 1));
		j = 0;
		split = ft_strsplit(map[i], ' ');
		while (j < col)
		{
			points[i][j] = ft_atoi(split[j]);
			j++;
		}
		ft_strdel(split);
		i++;
	}
	return (points);
}
