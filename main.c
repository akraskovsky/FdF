/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:02:37 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/06 19:18:36 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	int     fd;
	t_map	*map;
	int		x;  // for test
	int		y;	// for test

	if (argc != 2)
		terminate("Usage: ./fdf map_filename");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		terminate("File error");
	if ((map = read_map(fd)) == NULL)
		terminate("Map error");
	print_map(map);
//	Test:
	x = 2;
	y = 3;
	printf("\nx=%d, y=%d, z=%d, color=%d\n", x, y, get_point(map, x, y).z, get_point(map, x, y).color);
//	draw_map(map);
	clean_map(map);
	close(fd);
	return (0);
}