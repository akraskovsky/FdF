/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:02:37 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/26 18:52:50 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	int     fd;
	t_map	*map;

	if (argc == 2)

		if ((fd = open(argv[1], O_RDONLY)) > 0)
		{
						map = read_map(fd);
			close(fd);
			if (map == NULL)
				ft_putendl("Map error");
			else
			{
				// main algorythm
				printf("matrix x=%d, y=%d\n", map->size_x, map->size_y);
				clean_map(map);
			}
		}
		else
			ft_putendl("File error");
	else
		ft_putendl("Usage: ./fdf map_filename");
	return (0);
}