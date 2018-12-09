/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 23:01:43 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/09 15:57:45 by nkamolba         ###   ########.fr       */
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

/*
static void	draw_diagonal_line(t_env *env, t_line l)
{
	double	delta_x;
	double	delta_y;
	double	delta_error;
	double	error;
	t_point	current;

	if (l.one.x > l.two.x)
		ft_swapint(&l.one.x, &l.two.x);
	delta_x = l.two.x - l.one.x;
	delta_y = l.two.y - l.one.y;
	delta_error = delta_y / delta_x;
	if (delta_error < 0)
		delta_error *= -1;
	error = 0;
	current = create_point(l.one.x, l.one.y);
	while (current.x < l.two.x)
	{
		printf("x: %d, y: %d\n", current.x, current.y);
		env->img[current.y * WINDOW_WIDTH + current.x] = 0xFFFFFF;
		error += delta_error;
		if (error >= 0.5 && error < 1)
		{
			current.y++;
			error--;
		}
		else
			current.y += delta_error;
		current.x++;
	}
}
*/

void		swap_point(t_line *l)
{
	t_point	temp;

	temp = l->one;
	l->one = l->two;
	l->two = temp;
}

static void	draw_diagonal_line(t_env *env, t_line l)
{
	int		count_m;
	double	m;
	double	slope_error;
	t_point	current;

	if (l.one.x > l.two.x)
		swap_point(&l);
	m = (double)(l.two.y - l.one.y) / (double)(l.two.x - l.one.x);
	slope_error = 0;
	current = create_point(l.one.x, l.one.y);
	while (current.x < l.two.x)
	{
		if (m > 2)
		{
			count_m = 0;
			while (count_m < m)
				env->img[(current.y + count_m++) * WINDOW_WIDTH + current.x] = 0xFFFFFF;
		}
		if (m < -2)
		{
			count_m = 0;
			while (count_m < -m)
				env->img[(current.y - count_m++) * WINDOW_WIDTH + current.x] = 0xFFFFFF;
		}

		env->img[current.y * WINDOW_WIDTH + current.x] = 0xFFFFFF;
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
