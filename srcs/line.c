/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 23:01:43 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/10 17:30:13 by nkamolba         ###   ########.fr       */
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

static void	draw_diagonal_line(t_env *env, t_line l)
{
	int		pixel;
	int		count_m;
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
		if (m > 2)
		{
			count_m = 0;
			while (count_m < m)
			{
				pixel = (int)((current.y + count_m++) * WINDOW_WIDTH + current.x);
				if (pixel >= 0 && pixel <= WINDOW_WIDTH * WINDOW_HEIGHT)
					env->img[pixel] = 0xFFFFFF;
			}
		}
		if (m < -2)
		{
			count_m = 0;
			while (count_m < -m)
			{
				pixel = (int)((current.y - count_m++) * WINDOW_WIDTH + current.x);
				if (pixel >= 0 && pixel <= WINDOW_WIDTH * WINDOW_HEIGHT)
					env->img[pixel] = 0xFFFFFF;
			}
		}

		pixel = (int)(current.y * WINDOW_WIDTH + current.x);
		if (pixel >= 0 && pixel <= WINDOW_WIDTH * WINDOW_HEIGHT)
			env->img[pixel] = 0xFFFFFF;
		slope_error += m - (double)(int)m;
		if (slope_error >= 0.5)
		{
			current.y++;
			slope_error--;
		}
		else if (slope_error < -0.5)
		{
			current.y--;
			slope_error++;
		}
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
