/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:20:37 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/12 11:09:41 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(t_map *map)
{
	t_fdf *fdf;

	fdf = NULL;
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		terminate("Initialization error");
	if (!(fdf->mlx = mlx_init()))
		terminate("Initialization error");
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF project")))
		terminate("Initialization error");
	fdf->map = map;
	if (!(fdf->img_ptr = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		terminate("Initialization error");
	if (!(fdf->image = mlx_get_data_addr(fdf->img_ptr, &fdf->bits_per_pixel, &fdf->size_line, &fdf->endian)))
		terminate("Initialization error");
	return (fdf);
}

void	pixel_to_image(t_fdf *fdf, t_pix pix)
{
	int	i;

	pix.x += fdf->map->center_x + fdf->map->shift_x;
	pix.y += fdf->map->center_y + fdf->map->shift_y;
	if ((0 <= pix.x && pix.x < WIDTH && 0 <= pix.y && pix.y < HEIGHT) && (pix.y > MENU_H || pix.x > MENU_W))
	{
		i = pix.x * fdf->bits_per_pixel / 8 + pix.y * fdf->size_line;
		fdf->image[i] = pix.color;
		fdf->image[i+1] = pix.color >> 8;
		fdf->image[i+2] = pix.color >> 16;
	}
}

void	fill_background(t_fdf *fdf)
{
	int	i;
	int	bpp;

	i = 0;
	bpp = fdf->bits_per_pixel / 8;
	while (i < HEIGHT * WIDTH * bpp)
	{
		fdf->image[i] = BG_COLOR;
		fdf->image[i+1] = BG_COLOR >> 8;
		fdf->image[i+2] = BG_COLOR >> 16;
		i += bpp;
	}
}
