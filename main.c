/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:02:37 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/11 12:19:23 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	int     fd;
	t_map	*map;

	if (argc != 2)
		terminate("Usage: ./fdf map_filename");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		terminate("File error");
	if ((map = read_map(fd)) == NULL)
		terminate("Map error");
	print_map(map);
	draw_map(map);
	clean_map(map);
	close(fd);
	return (0);
}