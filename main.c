/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:02:37 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/27 17:42:52 by fprovolo         ###   ########.fr       */
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
			if ((map = read_map(fd)) == NULL)
				ft_putendl("Map error");
			else
			{
				print_map(map);
				draw_map(map);
				clean_map(map);
			}
			close(fd);
		}
		else
			ft_putendl("File error");
	else
		ft_putendl("Usage: ./fdf map_filename");
	return (0);
}