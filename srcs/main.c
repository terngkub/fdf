/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:54:12 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/09 17:46:46 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_change(t_env *env)
{
	ft_bzero(env->img, WINDOW_WIDTH * WINDOW_HEIGHT * 4);
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
		env->rot_y -= 0.1;
		display_change(env);
	}
	if (key == KEY_6)
	{
		env->rot_y += 0.1;
		display_change(env);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;
	int		**z;

	z = parse_file(argc, argv);
	create_map(&env, z);
	init_env(&env);
	draw_map(&env);
	mlx_key_hook(env.win_ptr, handle_key, NULL);
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img_ptr, 0, 0);
	printf("%d\n", (int)(-1.8));
	mlx_loop(env.mlx_ptr);
	return (0);
}