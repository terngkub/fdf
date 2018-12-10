/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:34:34 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/10 17:46:52 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotateX(t_env *env, t_coord *coord)
{
    t_coord new;

    new.x = coord->x * cos(env->rot_x) - coord->z * sin(env->rot_x);
    new.z = coord->z * cos(env->rot_x) + coord->x * sin(env->rot_x);
    coord->x = new.x;
    coord->z = new.z;
}

static void	rotateY(t_env *env, t_coord *coord)
{
    t_coord new;

    new.y = coord->y * cos(env->rot_y) - coord->z * sin(env->rot_y);
    new.z = coord->z * cos(env->rot_y) + coord->y * sin(env->rot_y);
    coord->y = new.y;
    coord->z = new.z;
}

static void	rotateZ(t_env *env, t_coord *coord)
{
    t_coord new;

    new.x = coord->x * cos(env->rot_z) - coord->y * sin(env->rot_z);
    new.y = coord->y * cos(env->rot_z) + coord->x * sin(env->rot_z);
    coord->x = new.x;
    coord->y = new.y;
}

void	    rotate(t_env *env, t_coord *coord)
{
    rotateX(env, coord);
    rotateY(env, coord);
    rotateZ(env, coord);
}