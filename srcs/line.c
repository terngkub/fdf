/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 23:01:43 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/12 18:14:23 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line		create_line(t_coord one, t_coord two)
{
	t_line	line;

	line.one = one;
	line.two = two;
	return (line);
}

void		swap_coord(t_line *l)
{
	t_coord	temp;

	temp = l->one;
	l->one = l->two;
	l->two = temp;
}

void		handle_slope_error(double m, double *slope_error, t_coord *current)
{
	*slope_error += m - (double)(int)m;
	if (*slope_error >= 0.5)
	{
		current->y += 1;
		*slope_error -= 1;
	}
	else if (*slope_error < -0.5)
	{
		current->y -= 1;
		*slope_error += 1;
	}
}

void		draw_pixel(t_env *env, t_coord coord, int color)
{
	int		pixel;

	if (coord.x < 0 || coord.x >= WINDOW_WIDTH || coord.y < 0 || coord.y >= WINDOW_HEIGHT)
		return ;
	pixel = (int)(coord.y * WINDOW_WIDTH + coord.x);
	if (pixel >= 0 && pixel < WINDOW_WIDTH * WINDOW_HEIGHT)
		env->img[pixel] = color;
}

int		get_color(t_env *env, t_line l, double percent)
{
	double	range_z;
	double	actual_z;
	double	percent_z;
	double	color;

	range_z = l.two.z_level - l.one.z_level;
	actual_z = l.one.z_level + range_z * percent;
	percent_z = (actual_z - env->min_z) / (env->max_z - env->min_z);
	/*
	if (percent_z <= 0)
		printf("one: %d, two: %d, percent_x: %f, range_z: %f, actual_z: %f, percent_z: %f\n", l.one.z_level, l.two.z_level, percent, range_z, actual_z, percent_z);
		*/
	color = 0x0000FF + percent_z * (0x00FF00 - 0x0000FF);
	return (int)color;
}

static void	draw_diagonal_line(t_env *env, t_line l)
{
	int		color;
	double	m;
	double	slope_error;
	t_coord	current;

	if (l.one.x > l.two.x)
		swap_coord(&l);
	m = (l.two.y - l.one.y) / (l.two.x - l.one.x);
	slope_error = 0;
	current = create_coord(l.one.x, l.one.y, 0, 0);

	while (current.x < l.two.x)
	{
		color = get_color(env, l, (current.x - l.one.x) / (l.two.x - l.one.x));
		draw_pixel(env, current, color);
		handle_slope_error(m, &slope_error, &current);
		current.y += (int)m;
		current.x++;
	}
}

static void	draw_vertical_line(t_env *env, t_line l)
{
	int y;

	if (l.two.y > l.two.y)
		swap_coord(&l);
	y = l.one.y;
	while (y < l.two.y)
		env->img[(int)(y++ * WINDOW_WIDTH + l.one.x)] = 0xFFFFFF;
}

void		draw_line(t_env *env, t_line l)
{
	if (l.one.x == l.two.x && l.one.y == l.two.y)
		env->img[(int)(l.one.y * WINDOW_WIDTH + l.one.x)] = 0xFFFFFF;
	else if (l.one.x == l.two.x)
		draw_vertical_line(env, l);
	else
		draw_diagonal_line(env, l);
}
