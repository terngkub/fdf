/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:56:57 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/08 18:23:57 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dummy_map(t_env *env)
{
	int		i;

	env->map = (t_point **)malloc(sizeof(t_point *) * 2);
	i = 0;
	while (i < 2)
		env->map[i++] = (t_point *)malloc(sizeof(t_point) * 2);
	env->map[0][0] = create_point(100, 100);
	env->map[0][1] = create_point(100, 200);
	env->map[1][0] = create_point(200, 100);
	env->map[1][1] = create_point(200, 200);
	env->map_width = 2;
	env->map_height = 2;
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
				printf("point1 x: %d y: %d\n", env->map[y][x].x, env->map[y][x].y);
				printf("point2 x: %d y: %d\n", env->map[y][x+1].x, env->map[y][x+1].y);
				draw_line(env, create_line(env->map[y][x], env->map[y][x + 1]));
			}
			if (y + 1 < env->map_height)
			{
				printf("point1 x: %d y: %d\n", env->map[y][x].x, env->map[y][x].y);
				printf("point2 x: %d y: %d\n", env->map[y+1][x].x, env->map[y+1][x].y);
				draw_line(env, create_line(env->map[y][x], env->map[y + 1][x]));
			}
			x++;
		}
		y++;
	}
}