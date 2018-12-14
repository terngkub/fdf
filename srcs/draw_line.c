/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 23:01:43 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/14 17:19:16 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_pixel(t_env *env, t_line l, t_coord coord, double percent)
{
	double	range_z;
	double	actual_z;
	double	percent_z;
	double	color;
	int		pixel;

	range_z = l.two.z_level - l.one.z_level;
	actual_z = l.one.z_level + range_z * percent;
	percent_z = (actual_z - env->min_z) / (env->max_z - env->min_z);
	color = 0x0000FF + percent_z * (0x00FF00 - 0x0000FF);
	if (coord.x < 0 || coord.x >= WINDOW_WIDTH
			|| coord.y < 0 || coord.y >= WINDOW_HEIGHT)
		return ;
	pixel = (int)(coord.y * WINDOW_WIDTH + coord.x);
	env->img[pixel] = color;
}

static void	draw_steep_line(t_env *env, t_line l, double m)
{
	double	slope_error;
	t_coord	current;

	if (l.one.y > l.two.y)
		swap_coord(&l);
	slope_error = 0;
	current = create_coord(l.one.x, l.one.y, 0, 0);
	while (current.y < l.two.y)
	{
		draw_pixel(env, l, current,
			(current.y - l.one.y) / (l.two.y - l.one.y));
		slope_error += (1 / m) - (double)(int)(1 / m);
		if (slope_error >= 0.5)
		{
			current.x += 1;
			slope_error -= 1;
		}
		else if (slope_error < -0.5)
		{
			current.x -= 1;
			slope_error += 1;
		}
		current.y++;
		current.x += (int)(1 / m);
	}
}

static void	draw_flat_line(t_env *env, t_line l, double m)
{
	double	slope_error;
	t_coord	current;

	if (l.one.x > l.two.x)
		swap_coord(&l);
	slope_error = 0;
	current = create_coord(l.one.x, l.one.y, 0, 0);
	while (current.x < l.two.x)
	{
		draw_pixel(env, l, current,
			(current.x - l.one.x) / (l.two.x - l.one.x));
		slope_error += m - (double)(int)m;
		if (slope_error >= 0.5)
		{
			current.y += 1;
			slope_error -= 1;
		}
		else if (slope_error < -0.5)
		{
			current.y -= 1;
			slope_error += 1;
		}
		current.y += (int)m;
		current.x++;
	}
}

static void	draw_vertical_line(t_env *env, t_line l)
{
	t_coord	current;

	if (l.one.y > l.two.y)
		swap_coord(&l);
	current = create_coord(l.one.x, l.one.y, 0, 0);
	while (current.y < l.two.y)
	{
		draw_pixel(env, l, current,
			(current.y - l.one.y) / (l.two.y - l.one.y));
		current.y++;
	}
}

void		draw_line(t_env *env, t_line l)
{
	double	m;

	if (l.one.x == l.two.x)
		draw_vertical_line(env, l);
	m = (l.two.y - l.one.y) / (l.two.x - l.one.x);
	if (m > -1 && m < 1)
		draw_flat_line(env, l, m);
	else
		draw_steep_line(env, l, m);
}
