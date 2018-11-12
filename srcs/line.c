/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 23:01:43 by nkamolba          #+#    #+#             */
/*   Updated: 2018/11/12 23:45:51 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_mlx mlx, t_line l)
{
	double	delta_x;
	double	delta_y;
	double	delta_error;
	double	error;
	int		x;
	int		y;

	if (l.x0 == l.x1 && l.y0 == l.y1)
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, l.x0, l.y0, 0xFFFFFF);
	else if (l.x0 == l.x1)
	{
		if (l.y0 > l.y1)
			ft_swapint(&l.y0, &l.y1);
		y = l.y0;
		while (y < l.y1)
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, l.x0, y++, 0xFFFFFF);
		return ;
	}
	else
	{
		if (l.x0 > l.x1)
			ft_swapint(&l.x0, &l.x1);
		delta_x = l.x1 - l.x0;
		delta_y = l.y1 - l.y0;
		delta_error = delta_y / delta_x;
		if (delta_error < 0)
			delta_error *= -1;
		error = 0;
		x = l.x0;
		y = l.y0;
		while (x < l.x1)
		{
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, x, y, 0xFFFFFF);
			error += delta_error;
			if (error >= 0.5)
			{
				y += ft_sign(delta_y);
				error--;
			}
			x++;
		}
	}
}