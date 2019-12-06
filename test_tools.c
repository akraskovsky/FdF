/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 10:51:14 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/06 18:56:56 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_map(t_map *map)
{
	int		x;
	int		y;

	printf("Field size: x=%d y=%d\n", map->size_x, map->size_y);
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			printf("%3d", map->z[y * map->size_x + x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

int		key_pressed(int key, void *param)
{
	void	*dummy;
	
	dummy = param;
	ft_putnbr(key);
	ft_putendl(" was pressed");
	if (key == 53)
		exit(0);
	return (0);
}