/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:35:21 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/12 14:56:46 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		open_file(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		printf("Usage: ./fdf [file]");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);	
	if (fd == -1)
	{
		printf("Can't open file");
		exit(1);
	}
	return fd;
}

int		get_split_len(char **split)
{
	int		len;

	len = 0;
	while(split[len])
		len++;
	return len;
}

int		*parse_line(t_env *env, char *line)
{
	char	**split;
	int		split_len;
	int		i;
	int		*row;

	if (!(split = ft_strsplit(line, ' ')))
		ft_error("ft_strplit fail");
	split_len = get_split_len(split);
	if (env->map_width == -1)
		env->map_width = split_len;
	if (env->map_width != split_len)
		ft_error("lines don't have the same width");
	if (!(row = (int *)malloc(sizeof(int) * split_len)))
		ft_error("malloc fail");
	i = 0;
	while (i < split_len)
	{
		row[i] = (int)ft_atoi(split[i]);
		i++;
	}
	return row;
}

t_queue	*read_file(t_env *env, int fd)
{
	char	*line;
	int		*row;
	t_queue	*z_queue;

	env->map_width = -1;
	get_next_line(fd, &line);
	row = parse_line(env, line);
	z_queue = ft_queue_create(sizeof(int *) * env->map_width);
	ft_queue_enqueue(z_queue, row);
	while (get_next_line(fd, &line) > 0)
	{
		row = parse_line(env, line);
		ft_queue_enqueue(z_queue, row);
	}
	env->map_height = z_queue->size;
	return z_queue;
}

void check_zlevel_minmax(t_env *env, int z_level)
{
	if (z_level < env->min_z)
		env->min_z = z_level;
	else if (z_level > env->min_z)
		env->max_z = z_level;
}

void	get_points(t_env *env, t_queue *z_queue)
{
	int		x;
	int		y;
	int		*z;

	if (!(env->points = (t_point **)malloc(sizeof(t_point *) * env->map_height)))
		ft_error("Error: malloc fail");
	y = 0;
	while (z_queue->size > 0)
	{
		if (!(env->points[y] = (t_point *)malloc(sizeof(t_point) * env->map_width)))
			ft_error("Error: malloc fail");
		z = (int *)ft_queue_dequeue(z_queue);
		x = 0;
		while (x < env->map_width)
		{
			env->points[y][x] = create_point(x, y, z[x]);
			check_zlevel_minmax(env, z[x]);
			x++;
		}
		y++;
	}
}

void	parse_file(t_env *env, int argc, char **argv)
{
	int		fd;
	t_queue	*z_queue;

	fd = open_file(argc, argv);
	z_queue = read_file(env, fd);
	close(fd);
	get_points(env, z_queue);
}