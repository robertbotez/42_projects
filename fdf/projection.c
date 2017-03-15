/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:17:24 by rbotez            #+#    #+#             */
/*   Updated: 2017/03/14 14:18:12 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minilibx_macos/mlx.h"
#include "includes/fdf.h"

void	ft_step(t_env *e)
{
	e->map->step = WMAX / (1 * (e->map->lines + e->map->col));
}

double	ft_x(double step, t_point p)
{
	double	x;

	x = 0.5 * WMAX + 0.5 * step * (p.x - p.y);
	return (x);
}

double	ft_y(double step, t_point p, double h_scale)
{
	double	y;

	y = (0.5 * HMAX + 0.5 * step * (p.x + p.y - 0.2 * p.z * h_scale)) / 2;
	return (y);
}

void	get_projection(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	while (i < e->map->lines)
	{
		j = 0;
		while (j < e->map->col)
		{
			get_color(e, i, j);
			e->points[i][j].x_i = ft_x(e->map->step, e->points[i][j]);
			e->points[i][j].y_i = ft_y(e->map->step,
					e->points[i][j], e->map->h_scale);
			j++;
		}
		i++;
	}
	move_map(e);
}
