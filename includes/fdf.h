/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:54:52 by nkamolba          #+#    #+#             */
/*   Updated: 2018/11/12 23:47:28 by nkamolba         ###   ########.fr       */
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
** Line
*/

typedef struct	s_line
{
	int			x0;
	int			x1;
	int			y0;
	int			y1;
}				t_line;

void			draw_line(t_mlx mlx, t_line l);

/*
** Utils
*/

int				ft_sign(double n);
void			ft_swapint(int *n1, int *n2);

#endif
