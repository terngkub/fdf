/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:56:57 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/09 17:32:16 by nkamolba         ###   ########.fr       */
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

void	create_map(t_env *env, int **z)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		c1;
	double	c2;
	double	c3;
	int		w;

	env->map = (t_point **)malloc(sizeof(t_point *) * 11);
	i = 0;
	while (i < 11)
	{
		env->map[i] = (t_point *)malloc(sizeof(t_point) * 19);
		j = 0;
		while (j < 19)
		{
			//x = j * 20 + (11 - i) * 10;
			//y = 10 + i * 20 - z[i][j] * 2;
			w = 30;
			c1 = 0;
			c2 = 0;
			c3 = 0.3;
			x = (j * w + i * c1) * (1 - c3) - c3 * z[i][j] * 2;
			y = (i - j * c1) * w * (1 - c2) - c2 * z[i][j] * 2;
			y += 0 * z[i][j];
			env->map[i][j] = create_point(x, y);
			j++;
		}
		i++;
	}
	env->map_width = 19;
	env->map_height = 11;
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
				draw_line(env, create_line(env->map[y][x], env->map[y][x + 1]));
			}
			if (y + 1 < env->map_height)
			{
				draw_line(env, create_line(env->map[y][x], env->map[y + 1][x]));
			}
			x++;
		}
		y++;
	}
}