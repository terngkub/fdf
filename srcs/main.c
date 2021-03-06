/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:54:12 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/14 20:04:04 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_env	env;
	t_queue *z_queue;

	z_queue = parse_file(&env, argc, argv);
	get_points(&env, z_queue);
	free(z_queue);
	fill_env(&env);
	display(&env);
	mlx_hook(env.win_ptr, 2, 1L << 0, handle_key, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
