/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:54:12 by nkamolba          #+#    #+#             */
/*   Updated: 2018/04/18 23:29:40 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "stdio.h"

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef struct	s_line
{
	int			x0;
	int			x1;
	int			y0;
	int			y1;
}				t_line;

int		ft_sign(double n)
{
	if (n > 0)
		return (1);
	else if (n < 0)
		return (-1);
	return (0);
}

void	ft_swapint(int *n1, int *n2)
{
	int		temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

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

int		main(void)
{
	t_mlx	mlx;
	t_line	line;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 500, 500, "mlx 42");
	line.x0 = 100;
	line.x1 = 400;
	line.y0 = 100;
	line.y1 = 400;
	draw_line(mlx, line);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
