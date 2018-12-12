/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:54:12 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/12 18:27:35 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_change(t_env *env)
{
	ft_bzero(env->img, WINDOW_WIDTH * WINDOW_HEIGHT * 4);
	get_coord(env);
	draw_map(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

int	handle_key(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (key == KEY_EXIT)
		exit(0);
	if (key == KEY_4)
	{
		env->rot_x += 0.1;
		display_change(env);
	}
	if (key == KEY_6)
	{
		env->rot_x -= 0.1;
		display_change(env);
	}
	if (key == KEY_5)
	{
		env->rot_y -= 0.1;
		display_change(env);
	}
	if (key == KEY_8)
	{
		env->rot_y += 0.1;
		display_change(env);
	}
	if (key == KEY_7)
	{
		env->rot_z -= 0.1;
		display_change(env);
	}
	if (key == KEY_9)
	{
		env->rot_z += 0.1;
		display_change(env);
	}
	if (key == KEY_2)
	{
		env->height_level -= 1;
		display_change(env);
	}
	if (key == KEY_3)
	{
		env->height_level += 1;
		display_change(env);
	}
	if (key == KEY_PLUS)
	{
		env->zoom_level += 1;
		display_change(env);
	}
	if (key == KEY_MINUS)
	{
		env->zoom_level -= 1;
		display_change(env);
	}
	if (key == KEY_LEFT)
	{
		env->adjust_x -= 10;
		display_change(env);
	}
	if (key == KEY_RIGHT)
	{
		env->adjust_x += 10;
		display_change(env);
	}
	if (key == KEY_UP)
	{
		env->adjust_y -= 10;
		display_change(env);
	}
	if (key == KEY_DOWN)
	{
		env->adjust_y += 10;
		display_change(env);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;

	parse_file(&env, argc, argv);
	init_env(&env);
	get_coord(&env);
	draw_map(&env);
	mlx_hook(env.win_ptr, 2, 1L << 0, handle_key, &env);
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img_ptr, 0, 0);
	mlx_loop(env.mlx_ptr);
	return (0);
}