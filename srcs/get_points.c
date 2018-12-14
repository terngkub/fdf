/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:45:46 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/14 20:03:46 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_zlevel_minmax(t_env *env, int z_level)
{
	if (z_level < env->min_z)
		env->min_z = z_level;
	else if (z_level > env->max_z)
		env->max_z = z_level;
}

void		get_points(t_env *env, t_queue *z_queue)
{
	int	x;
	int	y;
	int	*z;

	env->min_z = DBL_MAX;
	env->max_z = DBL_MIN;
	if (!(env->points = (t_point **)malloc(sizeof(t_point *)
			* env->map_height)))
		ft_error("Error: malloc fail");
	y = 0;
	while (z_queue->size > 0)
	{
		if (!(env->points[y] = (t_point *)malloc(sizeof(t_point)
				* env->map_width)))
			ft_error("Error: malloc fail");
		z = (int *)ft_queue_dequeue(z_queue);
		x = 0;
		while (x < env->map_width)
		{
			env->points[y][x] = create_point(x, y, z[x]);
			check_zlevel_minmax(env, z[x++]);
		}
		free(z);
		y++;
	}
}
