/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:25:31 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/11 17:21:10 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pix get_point(t_map *map, int x, int y)
{
	t_pix point;

	point.x = ((x - map->size_x / 2) * map->scale_xy) + map->shift_x;
	point.y = ((y - map->size_y / 2) * map->scale_xy) + map->shift_y;
	point.z = map->z[y * map->size_x + x] * map->scale_z;
	point.color = map->color[y * map->size_x + x];
	return (point);
}

int color(t_pix start, t_pix end, t_pix curr)
{
	int red;
	int green;
	int blue;
	double pcnt;

	pcnt = percent(start, end, curr);
	red = (start.color >> 16 & 0xFF) + ((end.color >> 16 & 0xFF) - (start.color >> 16 & 0xFF)) * pcnt;
	green = (start.color >> 8 & 0xFF) + ((end.color >> 8 & 0xFF) - (start.color >> 8 & 0xFF)) * pcnt;
	blue = (start.color & 0xFF) + ((end.color & 0xFF) - (start.color & 0xFF)) * pcnt;
	return ((red << 16) + (green << 8) + blue);
}

t_pix	iso(t_pix pix)
{
	pix.x = (pix.x - pix.y) * cos(0.8);
	pix.y = (pix.x + pix.y) * sin(0.8) - pix.z;
	return (pix);
}
void 	draw_line(t_fdf *fdf, t_pix start, t_pix end)
{
	t_pix delta;
	t_pix sign;
	t_pix curr;
	int error[2];

	delta.x = ft_abs(end.x - start.x);
	delta.y = ft_abs(end.y - start.y);
	sign.x = (start.x < end.x) ? 1 : -1;
	sign.y = (start.y < end.y) ? 1 : -1;
	error[0] = delta.x - delta.y;
//	mlx_pixel_put(fdf->mlx, fdf->win, end.x + fdf->map->center_x, end.y + fdf->map->center_y, end.color);
	curr = start;
	while (curr.x != end.x || curr.y != end.y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, curr.x + fdf->map->center_x, curr.y + fdf->map->center_y, color(start, end, curr));
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			curr.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			curr.y += sign.y;
		}
	}
}

void draw_map(t_map *map)
{
	t_fdf *fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		terminate("Initialization error");
	if (!(fdf->mlx = mlx_init()))
		terminate("Initialization error");
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF project")))
		terminate("Initialization error");
	fdf->map = map;
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);

	push_map(fdf);
	mlx_key_hook(fdf->win, key_pressed, fdf);
	mlx_loop(fdf->mlx);
	return;
}