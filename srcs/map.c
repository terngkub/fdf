/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:56:57 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/12 18:13:25 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_minmax(t_env *env, int x, int y)
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

void reset_minmax(t_env *env)
{
	env->min_x = DBL_MAX;
	env->max_x = DBL_MIN;
	env->min_y = DBL_MAX;
	env->max_y = DBL_MIN;
}

void adjust_position(t_env *env)
{
	double center_x;
	double center_y;
	int	y;
	int	x;

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

void	get_coord(t_env *env)
{
	int	y;
	int x;
	t_point	point;

	if (!(env->coords = (t_coord **)malloc(sizeof(t_coord *) * env->map_height)))
		ft_error("Error: malloc fail");
	reset_minmax(env);
	y = 0;
	while (y < env->map_height)
	{
		if (!(env->coords[y] = (t_coord *)malloc(sizeof(t_coord) * env->map_width)))
			ft_error("Error: malloc fail");
		x = 0;
		while (x < env->map_width)
		{
			point = env->points[y][x];
			env->coords[y][x] = create_coord(point.x * env->zoom_level, point.y * env->zoom_level, point.z * env->height_level, point.z);
			rotate(env, &(env->coords[y][x]));
			check_minmax(env, x, y);
			x++;
		}
		y++;
	}
	adjust_position(env);
}

void	draw_map(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->map_height)
	{
		x = 0;
		while (x < env->map_width)
		{
			if (x + 1 < env->map_width)
			{
				draw_line(env, create_line(env->coords[y][x], env->coords[y][x + 1]));
			}
			if (y + 1 < env->map_height)
			{
				draw_line(env, create_line(env->coords[y][x], env->coords[y + 1][x]));
			}
			x++;
		}
		y++;
	}
}

void	print_points(t_env *env)
{
	int		x;
	int		y;
	t_point	point;

	y = 0;
	while (y < env->map_height)
	{
		x = 0;
		while (x < env->map_width)
		{
			point = env->points[y][x];
			printf("%d,%d,%d ", point.x, point.y, point.z);
			x++;
		}
		printf("\n");
		y++;
	}
}