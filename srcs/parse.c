/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:35:21 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/08 22:23:49 by nkamolba         ###   ########.fr       */
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
	t_queue	*z_rows;
	char	*line;
	char	**split;
	int		i;
	int		*row;
	int		split_len;

	z_rows = ft_queue_create(sizeof(int *));
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		split_len = get_split_len(split);
		row = (int *)malloc(sizeof(int) * split_len);
		// TODO handle malloc
		i = 0;
		while (i < split_len)
		{
			row[i] = (int)ft_atoi(split[i]);
			printf("%d ", row[i]);
			i++;
		}
		ft_queue_enqueue(z_rows, row);
		printf("\n");
	}
	return z_rows;
}
/*

int		**get_altitude(t_queue *)
{
	

}

int		**parse_file(int argc, char **argv)
{
	int		fd;

	fd = open_file(argc, argv);
	read_file(fd);
	close(fd);
	return get_altitude();
}
*/