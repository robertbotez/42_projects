/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:14:19 by rbotez            #+#    #+#             */
/*   Updated: 2017/03/14 14:17:20 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minilibx_macos/mlx.h"
#include "includes/fdf.h"

void	get_color(t_env *e, int i, int j)
{
	get_color_shade(e);
	if (e->points[i][j].z < 3)
		e->points[i][j].color = 0xFF0000 + e->points[i][j].color_shade;
	if (e->points[i][j].z >= 3 && e->points[i][j].z <= 6)
		e->points[i][j].color = 0x00FF00 + e->points[i][j].color_shade;
	if (e->points[i][j].z > 6)
		e->points[i][j].color = 0x0000FF + e->points[i][j].color_shade;
}

void	get_extremity(t_env *e)
{
	int		i;
	int		j;
	double	min;
	double	max;

	i = 0;
	min = e->points[0][0].z;
	max = e->points[0][0].z;
	while (i < e->map->lines)
	{
		j = 0;
		while (j < e->map->col)
		{
			if (e->points[i][j].z < min)
				min = e->points[i][j].z;
			if (e->points[i][j].z > max)
				max = e->points[i][j].z;
			j++;
		}
		i++;
	}
	e->map->z_min = min;
	e->map->z_max = max;
}

void	get_color_shade(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	get_extremity(e);
	while (i < e->map->lines)
	{
		j = 0;
		while (j < e->map->col)
		{
			if (e->map->z_min != e->map->z_max)
				e->points[i][j].color_shade = 344 - 344 *
				(e->points[i][j].z - e->map->z_min) /
				(e->map->z_max - e->map->z_min);
			else
				e->points[i][j].color_shade = 344 - 344 *
				(e->points[i][j].z - e->map->z_min);
			j++;
		}
		i++;
	}
}
