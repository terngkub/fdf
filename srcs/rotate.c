/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:34:34 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/14 17:23:53 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_env *env, t_coord *coord)
{
	t_coord new;

	new.x = coord->x * cos(env->rot_x) - coord->z * sin(env->rot_x);
	new.z = coord->z * cos(env->rot_x) + coord->x * sin(env->rot_x);
	coord->x = new.x;
	coord->z = new.z;
}

static void	rotate_y(t_env *env, t_coord *coord)
{
	t_coord new;

	new.y = coord->y * cos(env->rot_y) - coord->z * sin(env->rot_y);
	new.z = coord->z * cos(env->rot_y) + coord->y * sin(env->rot_y);
	coord->y = new.y;
	coord->z = new.z;
}

static void	rotate_z(t_env *env, t_coord *coord)
{
	t_coord new;

	new.x = coord->x * cos(env->rot_z) - coord->y * sin(env->rot_z);
	new.y = coord->y * cos(env->rot_z) + coord->x * sin(env->rot_z);
	coord->x = new.x;
	coord->y = new.y;
}

void		rotate(t_env *env, t_coord *coord)
{
	rotate_x(env, coord);
	rotate_y(env, coord);
	rotate_z(env, coord);
}
