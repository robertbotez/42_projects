/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:59:40 by rbotez            #+#    #+#             */
/*   Updated: 2017/03/14 13:59:58 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "includes/minilibx_macos/mlx.h"

t_point	**alloc_points(int line, int col)
{
	t_point	**points;
	int		i;

	i = 0;
	points = (t_point **)malloc(sizeof(t_point *) * line);
	while (i < line)
	{
		points[i] = (t_point *)malloc(sizeof(t_point) * col);
		i++;
	}
	return (points);
}

void	get_lines_and_columns(t_env *e, char *av)
{
	e->map->lines = ft_alloc(av);
	e->map->col = columns(ft_read(av), e->map->lines);
}

void	get_coordinates(t_env *e, int **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (i < e->map->lines)
	{
		j = 0;
		while (j < e->map->col)
		{
			e->points[i][j].x = j;
			e->points[i][j].y = i;
			e->points[i][j].z = numbers[i][j];
			j++;
		}
		i++;
	}
}
