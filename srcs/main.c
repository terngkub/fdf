/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:54:12 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/08 22:04:19 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key(int key, void *param)
{
	(void)param;
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}

/*
int		main(void)
{
	t_env	env;

	dummy_map(&env);
	init_env(&env);
	draw_map(&env);
	mlx_key_hook(env.win_ptr, handle_key, NULL);
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img_ptr, 0, 0);
	mlx_loop(env.mlx_ptr);
	return (0);
}
*/

int		main(int argc, char **argv)
{
	int fd;
	t_queue *z_rows;

	fd = open_file(argc, argv);
	printf("fd: %d\n", fd);
	z_rows = read_file(fd);
	printf("rows: %zu\n", z_rows->size);
	return (0);
}