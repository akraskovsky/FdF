/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:02:37 by fprovolo          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/12/11 18:21:16 by jmalik           ###   ########.fr       */
=======
/*   Updated: 2019/12/11 12:19:23 by fprovolo         ###   ########.fr       */
>>>>>>> 0db513214b6783065418c20613c9d6df133fcea2
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