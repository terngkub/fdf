/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:35:21 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/09 13:14:32 by nkamolba         ###   ########.fr       */
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

t_queue	*read_file(int fd)
{
	t_queue	*z_queue;
	char	*line;
	char	**split;
	int		i;
	int		*row;
	int		split_len;

	z_queue = ft_queue_create(sizeof(int *) * 19);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		split_len = get_split_len(split);
		if (!(row = (int *)malloc(sizeof(int) * split_len)))
			;
		i = 0;
		while (i < split_len)
		{
			row[i] = (int)ft_atoi(split[i]);
			i++;
		}
		ft_queue_enqueue(z_queue, row);
	}
	return z_queue;
}

int		**get_z(t_queue *z_queue)
{
	int		**z;
	int		i;

	if (!(z = (int **)malloc(sizeof(int *) * z_queue->size)))
		;
	i = 0;
	while (z_queue->size > 0)
	{
		z[i] = (int *)ft_queue_dequeue(z_queue);
		i++;
	}
	return z;
}

int		**parse_file(int argc, char **argv)
{
	int		fd;
	t_queue	*z_queue;

	fd = open_file(argc, argv);
	z_queue = read_file(fd);
	close(fd);
	return get_z(z_queue);
}