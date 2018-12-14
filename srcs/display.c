/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:25:19 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/14 17:28:22 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display(t_env *env)
{
	ft_bzero(env->img, WINDOW_WIDTH * WINDOW_HEIGHT * 4);
	get_coord(env);
	draw_map(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}
