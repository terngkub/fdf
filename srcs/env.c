/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:59:48 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/15 13:33:44 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_env(t_env *env)
{
	int		bpp;
	int		size_line;
	int		endian;

	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
		"mlx 42");
	env->img_ptr = mlx_new_image(env->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	bpp = 32;
	size_line = WINDOW_WIDTH * 4;
	endian = 1;
	env->img = (int *)mlx_get_data_addr(env->img_ptr, &bpp, &size_line,
		&endian);
	env->zoom_level = 20;
	env->height_level = 1;
	env->rot_x = acos(tan(M_PI * 30 / 180));
	env->rot_y = 0;
	env->rot_z = M_PI * 45 / 180;
	env->adjust_x = 0;
	env->adjust_y = 0;
	env->displayed = 0;
}
