/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 10:51:14 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/09 14:13:26 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_map(t_map *map)
{
	int		x;
	int		y;

	printf("\nField size: x=%d y=%d\n", map->size_x, map->size_y);
	printf("Min_z=%d max_z=%d\n", map->min_z, map->max_z);
	printf("Scale: x,y=%d z=%d\n", map->scale_xy, map->scale_z);
	printf("Window center: x=%d y=%d\n-------\n", map->center_x, map->center_y);
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