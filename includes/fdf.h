/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:54:52 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/09 17:32:14 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define KEY_EXIT 53
# define KEY_4 86
# define KEY_5 87
# define KEY_6 88
# define KEY_7 89
# define KEY_8 91
# define KEY_9 92



int		**parse_file(int argc, char **argv);

/*
** Point
*/

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

t_point			create_point(int x, int y);
t_queue	*read_file(int fd);

/*
** Environment
*/

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img;

	t_point		**map;
	int			map_width;
	int			map_height;

	double		rot_x;
	double		rot_y;
	double		rot_z;

}				t_env;

void	init_env(t_env *env);


/*
** Line
*/

typedef struct	s_line
{
	t_point		one;
	t_point		two;
}				t_line;

t_line			create_line(t_point one, t_point two);
void			draw_line(t_env *env, t_line l);

/*
** Map
*/

void			dummy_map(t_env *env);
void			create_map(t_env *env, int **z);
void			draw_map(t_env *env);



/*
** Utils
*/

int				ft_sign(double n);
void			ft_swapint(int *n1, int *n2);

#endif
