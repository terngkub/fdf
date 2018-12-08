/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 23:01:43 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/08 19:25:30 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line		create_line(t_point one, t_point two)
{
	t_line	line;

	line.one = one;
	line.two = two;
	return (line);
}

static void	draw_diagonal_line(t_env *env, t_line l)
{
	double	delta_y;
	double	delta_error;
	double	error;
	t_point	current;

	if (l.one.x > l.two.x)
		ft_swapint(&l.one.x, &l.two.x);
	delta_y = l.two.y - l.one.y;
	delta_error = delta_y / (l.two.x - l.one.x);
	if (delta_error < 0)
		delta_error *= -1;
	error = 0;
	current = create_point(l.one.x, l.one.y);
	while (current.x < l.two.x)
	{
		env->img[current.y * WINDOW_WIDTH + current.x] = 0xFFFFFF;
		error += delta_error;
		if (error >= 0.5)
		{
			current.y += ft_sign(delta_y);
			error--;
		}
		current.x++;
	}
}

static void	draw_vertical_line(t_env *env, t_line l)
{
	int y;

	if (l.two.y > l.two.y)
		ft_swapint(&l.one.y, &l.two.y);
	y = l.one.y;
	while (y < l.two.y)
		env->img[y++ * WINDOW_WIDTH + l.one.x] = 0xFFFFFF;
}

void		draw_line(t_env *env, t_line l)
{
	if (l.one.x == l.two.x && l.one.y == l.two.y)
		env->img[l.one.y * WINDOW_WIDTH + l.one.x] = 0xFFFFFF;
	else if (l.one.x == l.two.x)
		draw_vertical_line(env, l);
	else
		draw_diagonal_line(env, l);
}
