/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:55:07 by rbotez            #+#    #+#             */
/*   Updated: 2017/03/14 14:53:52 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minilibx_macos/mlx.h"
#include "includes/fdf.h"

void		move_key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 0)
		e->map->x_move -= 20;
	if (keycode == 2)
		e->map->x_move += 20;
	if (keycode == 1)
		e->map->y_move += 20;
	if (keycode == 13)
		e->map->y_move -= 20;
	if (keycode == 4)
		e->map->h_scale += 0.2;
	if (keycode == 38)
		e->map->h_scale -= 0.2;
	if (keycode == 69)
		e->map->step += 10;
	if (keycode == 78)
		e->map->step -= 10;
}

void		ft_print_tutorial(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 30, 30, 0xFFFFFF, "Exit program : ESC");
	mlx_string_put(e->mlx, e->win, 30, 60, 0xFFFFFF,
	"Move map: up(w), down(s), left(a), right(d)");
	mlx_string_put(e->mlx, e->win, 30, 90, 0xFFFFFF, "Reset map: r");
	mlx_string_put(e->mlx, e->win, 30, 120, 0xFFFFFF, "Zoom in/out: +/-");
	mlx_string_put(e->mlx, e->win, 30, 150, 0xFFFFFF,
	"Incrase/Decrease height scale: h/j");
}

int			expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	draw(e);
	ft_print_tutorial(e);
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	move_key_hook(keycode, e);
	if (keycode == 15)
		ft_default(e);
	get_projection(e);
	expose_hook(e);
	return (0);
}
