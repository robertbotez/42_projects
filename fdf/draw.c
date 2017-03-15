/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:00:40 by rbotez            #+#    #+#             */
/*   Updated: 2017/03/14 14:53:04 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minilibx_macos/mlx.h"
#include "includes/fdf.h"

void			new_window(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WMAX, HMAX, "FdF");
}

double			ft_abs(float a)
{
	if (a >= 0)
		return (a);
	return (-a);
}

void			draw_line(t_env *e, t_point a, t_point b, int i)
{
	t_draw	d;

	d.sx = b.x_i < a.x_i ? 1 : -1;
	d.sy = b.y_i < a.y_i ? 1 : -1;
	d.dx = ft_abs(a.x_i - b.x_i);
	d.dy = ft_abs(a.y_i - b.y_i);
	d.err = (d.dx > d.dy ? d.dx : -d.dy) / 2;
	while (i++ < get_max(d.dx, d.dy))
	{
		mlx_pixel_put(e->mlx, e->win, b.x_i, b.y_i, b.color);
		if (b.x_i == a.x_i && b.y_i == a.y_i)
			break ;
		d.e2 = d.err;
		if (d.e2 > -d.dx)
		{
			d.err -= d.dy;
			b.x_i += d.sx;
		}
		if (d.e2 < d.dy)
		{
			d.err += d.dx;
			b.y_i += d.sy;
		}
	}
}

double			get_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void			draw(t_env *e)
{
	t_point	**point;
	int		i;
	int		j;

	point = e->points;
	i = 0;
	while (i < e->map->lines)
	{
		j = 0;
		while (j < e->map->col)
		{
			if (i < e->map->lines - 1)
				draw_line(e, point[i][j], point[i + 1][j], 0);
			if (j < e->map->col - 1)
				draw_line(e, point[i][j], point[i][j + 1], 0);
			j++;
		}
		i++;
	}
}
