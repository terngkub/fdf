/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:52:23 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/14 18:56:52 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_map(t_env *env)
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
				draw_line(env,
					create_line(env->coords[y][x], env->coords[y][x + 1]));
			if (y + 1 < env->map_height)
				draw_line(env,
					create_line(env->coords[y][x], env->coords[y + 1][x]));
			x++;
		}
		y++;
	}
}
