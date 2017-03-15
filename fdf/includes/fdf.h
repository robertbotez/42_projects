/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:23:07 by rbotez            #+#    #+#             */
/*   Updated: 2017/03/14 14:52:33 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "get_next_line.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# define WMAX 1080
# define HMAX 720

typedef struct	s_point{
	double	x;
	double	y;
	double	z;
	double	x_i;
	double	y_i;
	double	color;
	double	color_shade;
}				t_point;

typedef	struct	s_draw{
	double	dx;
	double	dy;
	double	err;
	double	sx;
	double	sy;
	double	e2;

}				t_draw;

typedef	struct	s_map
{
	int		lines;
	int		col;
	double	step;
	double	z_min;
	double	z_max;
	double	y_move;
	double	x_move;
	double	h_scale;
	double	zoom;
}				t_map;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_point **points;
	t_map	*map;
}				t_env;

int				get_next_line(int const fd, char **line);
char			**ft_read(char *av);
int				ft_alloc(char *av);
int				columns(char **map, int lines);
int				**ft_convert(char **map, int lines, int col);
void			new_window(t_env *e);
double			ft_abs(float	a);
void			draw_line(t_env	*e, t_point a, t_point b, int i);
void			draw(t_env *e);
t_point			**alloc_points(int line, int col);
void			get_lines_and_columns(t_env *e, char *av);
void			get_coordinates(t_env *e, int **numbers);
void			init_e(t_env *e, int argc, char **argv);
int				exit_err(void);
double			get_max(float a, float b);
void			ft_step(t_env *e);
double			ft_x(double step, t_point p);
double			ft_y(double step, t_point p, double h_scale);
void			get_projection(t_env *e);
void			get_color(t_env *e, int i, int j);
void			get_extremity(t_env *e);
void			get_color_shade(t_env *e);
void			move_map(t_env *e);
void			move_key_hook(int keycode, t_env *e);
int				key_hook(int keycode, t_env *e);
void			ft_print_tutorial(t_env *e);
int				expose_hook(t_env *e);
void			ft_default(t_env *e);

#endif
