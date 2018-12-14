/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:35:21 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/14 19:52:26 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		open_file(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		ft_error("wrong number of parameter\nUsage: ./fdf [file]");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("can't open file");
	return (fd);
}

static int		get_split_len(char **split)
{
	int		len;

	len = 0;
	while (split[len])
		len++;
	return (len);
}

static int		*parse_line(t_env *env, char *line)
{
	char		**split;
	int			split_len;
	int			i;
	int			*row;

	if (!(split = ft_strsplit(line, ' ')))
		ft_error("ft_strplit fail in parse_line");
	split_len = get_split_len(split);
	if (env->map_width == -1)
		env->map_width = split_len;
	if (env->map_width != split_len)
		ft_error("lines don't have the same width");
	if (!(row = (int *)malloc(sizeof(int) * split_len)))
		ft_error("malloc fail in parse_line");
	i = 0;
	while (i < split_len)
	{
		row[i] = (int)ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (row);
}

static t_queue	*read_file(t_env *env, int fd)
{
	char	*line;
	int		*row;
	t_queue	*z_queue;
	int		gnl;

	env->map_width = -1;
	get_next_line(fd, &line);
	row = parse_line(env, line);
	free(line);
	z_queue = ft_queue_create(sizeof(int *) * env->map_width);
	ft_queue_enqueue(z_queue, row);
	free(row);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		row = parse_line(env, line);
		free(line);
		ft_queue_enqueue(z_queue, row);
		free(row);
	}
	if (gnl == -1)
		ft_error("get_next_line failed");
	env->map_height = z_queue->size;
	return (z_queue);
}

t_queue			*parse_file(t_env *env, int argc, char **argv)
{
	int		fd;
	t_queue	*z_queue;

	fd = open_file(argc, argv);
	z_queue = read_file(env, fd);
	close(fd);
	return (z_queue);
}
