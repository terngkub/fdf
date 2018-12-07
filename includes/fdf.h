/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:54:52 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/07 19:53:20 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

/*
** Point
*/

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

t_point			create_point(int x, int y);

/*
** Line
*/

typedef struct	s_line
{
	t_point		one;
	t_point		two;
}				t_line;

t_line			create_line(t_point one, t_point two);
void			draw_line(t_mlx mlx, t_line l);

/*
** Utils
*/

int				ft_sign(double n);
void			ft_swapint(int *n1, int *n2);

#endif
