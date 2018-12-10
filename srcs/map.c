/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:56:57 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/10 19:57:18 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_coord(t_env *env)
{
	int	y;
	int x;
	t_point	point;

	if (!(env->coords = (t_coord **)malloc(sizeof(t_coord *) * env->map_height)))
		ft_error("Error: malloc fail");
	y = 0;
	while (y < env->map_height)
	{
		if (!(env->coords[y] = (t_coord *)malloc(sizeof(t_coord) * env->map_width)))
			ft_error("Error: malloc fail");
		x = 0;
		while (x < env->map_width)
		{
			point = env->points[y][x];
			env->coords[y][x] = create_coord(point.x * env->zoom_level, point.y * env->zoom_level, point.z * env->height_level);
			env->coords[y][x].x += env->adjust_x;
			env->coords[y][x].y += env->adjust_y;
			rotate(env, &(env->coords[y][x]));
			x++;
		}
		y++;
	}
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