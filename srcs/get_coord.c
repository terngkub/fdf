/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:56:57 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/14 20:09:34 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_minmax(t_env *env, int x, int y)
{
	int	coord_x;
	int	coord_y;

	coord_x = env->coords[y][x].x;
	coord_y = env->coords[y][x].y;
	if (coord_x < env->min_x)
		env->min_x = coord_x;
	else if (coord_x > env->max_x)
		env->max_x = coord_x;
	if (coord_y < env->min_y)
		env->min_y = coord_y;
	else if (coord_y > env->max_y)
		env->max_y = coord_y;
}

static void	reset_minmax(t_env *env)
{
	env->min_x = DBL_MAX;
	env->max_x = DBL_MIN;
	env->min_y = DBL_MAX;
	env->max_y = DBL_MIN;
}

static void	adjust_position(t_env *env)
{
	double	center_x;
	double	center_y;
	int		y;
	int		x;

	center_x = (WINDOW_WIDTH - env->max_x + env->min_x) / 2 - env->min_x;
	center_y = (WINDOW_HEIGHT - env->max_y + env->min_y) / 2 - env->min_y;
	y = 0;
	while (y < env->map_height)
	{
		x = 0;
		while (x < env->map_width)
		{
			env->coords[y][x].x += center_x + env->adjust_x;
			env->coords[y][x].y += center_y + env->adjust_y;
			x++;
		}
		y++;
	}
}

static void	add_coord(t_env *env, int x, int y)
{
	t_point	point;

	point = env->points[y][x];
	env->coords[y][x] = create_coord(point.x * env->zoom_level,
		point.y * env->zoom_level,
		(int)(point.z * env->height_level), point.z);
	rotate(env, &(env->coords[y][x]));
	check_minmax(env, x, y);
}

void		get_coord(t_env *env)
{
	int		y;
	int		x;

	if (!(env->coords = (t_coord **)malloc(sizeof(t_coord *)
			* env->map_height)))
		ft_error("Error: malloc fail");
	reset_minmax(env);
	y = 0;
	while (y < env->map_height)
	{
		if (!(env->coords[y] = (t_coord *)malloc(sizeof(t_coord)
				* env->map_width)))
			ft_error("Error: malloc fail");
		x = 0;
		while (x < env->map_width)
		{
			add_coord(env, x, y);
			x++;
		}
		y++;
	}
	adjust_position(env);
}
