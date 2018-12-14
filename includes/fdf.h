/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:54:52 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/14 21:37:38 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define KEY_EXIT 53
# define KEY_2 84
# define KEY_3 85
# define KEY_4 86
# define KEY_5 87
# define KEY_6 88
# define KEY_7 89
# define KEY_8 91
# define KEY_9 92
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

/*
** Structure
*/

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
	int			z_level;
}				t_coord;

typedef struct	s_line
{
	t_coord		one;
	t_coord		two;
}				t_line;

t_point			create_point(int x, int y, int z);
t_coord			create_coord(int x, int y, int z, int z_level);
t_line			create_line(t_coord one, t_coord two);
void			swap_coord(t_line *l);

/*
** Environment
*/

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img;
	t_point		**points;
	t_coord		**coords;
	int			map_width;
	int			map_height;
	int			zoom_level;
	double		height_level;
	int			adjust_x;
	int			adjust_y;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	double		min_z;
	double		max_z;
}				t_env;

void			fill_env(t_env *env);

/*
** Parse
*/

t_queue			*parse_file(t_env *env, int argc, char **argv);

/*
** Get Point
*/

void			get_points(t_env *env, t_queue *z_queue);

/*
** Display
*/

void			get_coord(t_env *env);
void			rotate(t_env *env, t_coord *coord);
void			draw_map(t_env *env);
void			draw_line(t_env *env, t_line l);
void			display(t_env *env);

/*
** Utils
*/

int				ft_sign(double n);
void			ft_swapint(int *n1, int *n2);
void			ft_error(char *str);

/*
** Key
*/

int				handle_key(int key, void *param);

#endif
