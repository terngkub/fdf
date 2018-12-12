/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 23:01:43 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/12 16:40:03 by nkamolba         ###   ########.fr       */
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

//256 * (256 - 255 * p)
void		draw_pixel(t_env *env, t_coord coord, t_line l)
{
	int		pixel;

	pixel = (int)(coord.y * WINDOW_WIDTH + coord.x);
	if (pixel >= 0 && pixel < WINDOW_WIDTH * WINDOW_HEIGHT)
		env->img[pixel] = 0x00FF00;
}

static void	draw_diagonal_line(t_env *env, t_line l)
{
	double	m;
	double	slope_error;
	t_coord	current;

	if (l.one.x > l.two.x)
		swap_coord(&l);
	m = (l.two.y - l.one.y) / (l.two.x - l.one.x);
	slope_error = 0;
	current = create_coord(l.one.x, l.one.y, 0);

	while (current.x < l.two.x)
	{
		draw_pixel(env, current);
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
