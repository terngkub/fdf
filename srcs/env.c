/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:59:48 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/09 17:48:00 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_env(t_env *env)
{
	int		bpp;
	int		size_line;
	int		endian;

	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx 42");
	env->img_ptr = mlx_new_image(env->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	bpp = 32;
	size_line = WINDOW_WIDTH * 4;
	endian = 1;
	env->img = (int *)mlx_get_data_addr(env->img_ptr, &bpp, &size_line, &endian);
	env->rot_x = 0;
	env->rot_y = 0;
	env->rot_z = 0;
}