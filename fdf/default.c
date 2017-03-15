/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:55:03 by rbotez            #+#    #+#             */
/*   Updated: 2017/03/14 13:55:04 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minilibx_macos/mlx.h"
#include "includes/fdf.h"

void	ft_default(t_env *e)
{
	e->map->x_move = 0;
	e->map->y_move = 0;
	e->map->h_scale = 1;
	e->map->zoom = 1;
	ft_step(e);
}
