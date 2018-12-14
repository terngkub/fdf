/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:56:21 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/14 17:57:23 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	create_point(int x, int y, int z)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_coord	create_coord(int x, int y, int z, int z_level)
{
	t_coord coord;

	coord.x = x;
	coord.y = y;
	coord.z = z;
	coord.z_level = z_level;
	return (coord);
}

t_line	create_line(t_coord one, t_coord two)
{
	t_line	line;

	line.one = one;
	line.two = two;
	return (line);
}

void	swap_coord(t_line *l)
{
	t_coord	temp;

	temp = l->one;
	l->one = l->two;
	l->two = temp;
}
