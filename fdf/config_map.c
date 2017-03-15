/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:54:55 by rbotez            #+#    #+#             */
/*   Updated: 2017/03/14 13:54:59 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minilibx_macos/mlx.h"
#include "includes/fdf.h"

void	move_map(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	while (i < e->map->lines)
	{
		j = 0;
		while (j < e->map->col)
		{
			e->points[i][j].x_i += e->map->x_move;
			e->points[i][j].y_i += e->map->y_move;
			j++;
		}
		i++;
	}
}
