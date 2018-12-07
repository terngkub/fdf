/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:54:12 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/07 18:58:38 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(void)
{
	t_mlx	mlx;
	t_point	one;
	t_point	two;
	t_line	line;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 500, 500, "mlx 42");
	one = create_point(100, 100);
	two = create_point(400, 300);
	line = create_line(one, two);
	draw_line(mlx, line);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
