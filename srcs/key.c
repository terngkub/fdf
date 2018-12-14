/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:06:14 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/14 22:53:49 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	handle_key_rotate(t_env *env, int key)
{
	int change;

	change = 1;
	if (key == KEY_4)
		env->rot_y += 0.1;
	else if (key == KEY_6)
		env->rot_y -= 0.1;
	else if (key == KEY_5)
		env->rot_x -= 0.1;
	else if (key == KEY_8)
		env->rot_x += 0.1;
	else if (key == KEY_7)
		env->rot_z -= 0.1;
	else if (key == KEY_9)
		env->rot_z += 0.1;
	else
		change = 0;
	return (change);
}

static int	handle_key_move(t_env *env, int key)
{
	int		change;

	change = 1;
	if (key == KEY_LEFT)
		env->adjust_x -= 10;
	else if (key == KEY_RIGHT)
		env->adjust_x += 10;
	else if (key == KEY_UP)
		env->adjust_y -= 10;
	else if (key == KEY_DOWN)
		env->adjust_y += 10;
	else
		change = 0;
	return (change);
}

static int	handle_key_height(t_env *env, int key)
{
	int		change;

	change = 1;
	if (key == KEY_2)
		env->height_level -= 0.1;
	else if (key == KEY_3)
		env->height_level += 0.1;
	else
		change = 0;
	return (change);
}

static int	handle_key_zoom(t_env *env, int key)
{
	int		change;

	change = 1;
	if (key == KEY_PLUS)
		env->zoom_level += 1;
	else if (key == KEY_MINUS)
		env->zoom_level -= 1;
	else
		change = 0;
	return (change);
}

int			handle_key(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (key == KEY_EXIT)
		exit(0);
	if (handle_key_rotate(env, key) || handle_key_move(env, key)
			|| handle_key_height(env, key) || handle_key_zoom(env, key))
		display(env);
	return (0);
}
