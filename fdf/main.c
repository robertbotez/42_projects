/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:00:26 by rbotez            #+#    #+#             */
/*   Updated: 2017/03/14 14:13:23 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minilibx_macos/mlx.h"
#include "includes/fdf.h"

int		exit_err(void)
{
	ft_putendl("Error");
	exit(EXIT_FAILURE);
	return (0);
}

void	init_e(t_env *e, int argc, char **argv)
{
	int	**a;

	if (argc != 2)
		exit_err();
	e->map = (t_map *)malloc(sizeof(t_map));
	get_lines_and_columns(e, argv[1]);
	a = ft_convert(ft_read(argv[1]), e->map->lines, e->map->col);
	e->points = alloc_points(e->map->lines, e->map->col);
	ft_default(e);
	get_coordinates(e, a);
	get_projection(e);
}

int		main(int argc, char **argv)
{
	t_env *e;

	e = (t_env *)malloc(sizeof(t_env));
	init_e(e, argc, argv);
	new_window(e);
	draw(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
