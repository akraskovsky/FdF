/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 10:51:14 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/12 00:14:18 by fprovolo         ###   ########.fr       */
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
int		ft_key(int key)
{
	return (key == 126 || key == 125 || key == 123 || key == 124 \
	|| key == 24 || key == 69 || key == 27 || key == 78 || \
	key == 86 || key == 88 || key == 21 || key == 22 || \
	key == 84 || key == 19 || key == 91 || key == 28 || key == 53);
}

void	made_key(int key, t_fdf *fdf)
{
	int		i;

	i = 0;
	if (key == 126)
		fdf->map->shift_y -= 10;
	if (key == 125)
		fdf->map->shift_y += 10;
	if (key == 124)
		fdf->map->shift_x += 10;
	if (key == 123)
		fdf->map->shift_x -= 10;
	if (key == 24 || key == 69)
		fdf->map->scale_xy += 3;
	if (key == 27 || key == 78)
		fdf->map->scale_xy -= 3;
	if (key == 84 || key == 19)
		fdf->map->scale_z -= 2;
	if (key == 91 || key == 28)
		fdf->map->scale_z += 2;
	if (key == 86 || key == 21)
		fdf->map->angle += 0.05;
	if (key == 88 || key == 22)
		fdf->map->angle -= 0.05;
	if (key == 53)
	{
		mlx_destroy_image(fdf->mlx, fdf->img_ptr);
		exit(0);
	}
}

int		key_pressed(int key, t_fdf *fdf)
{
	if (ft_key(key))
	{
//		mlx_clear_window(fdf->mlx, fdf->win);	
//		ft_drow_menu(*fdf);
		made_key(key, fdf);
		push_map(fdf);
	
		ft_putnbr(key);
		ft_putendl(" was pressed");
	}	
	return (0);
}

void	test_of_colors(t_fdf *fdf)
{
	int	color;
	int	color2;

	color = 0xFF8844;
	color2 = mlx_get_color_value(fdf->mlx, color);
	printf("*** color test ***\norigin: %10X\nnew: %10X\nendian = %d, bpp = %d, line = %d\n-------\n", 
			color, color2, fdf->endian, fdf->bits_per_pixel, fdf->size_line);
}