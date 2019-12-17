/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:25:31 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/17 15:51:28 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

t_pix get_point(t_map *map, int x, int y)
{
	t_pix point;
	point.x = ((x - map->size_x / 2) * map->scale_xy);
	point.y = ((y - map->size_y / 2) * map->scale_xy);

	point.z = map->z[y * map->size_x + x] * map->scale_z;
	if (map->alt_col > 0)
		point.color = get_alt_color(map, point.z);
	else
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
	curr = start;
	while (curr.x != end.x || curr.y != end.y)
	{
		curr.color = color(start, end, curr);
		pixel_to_image(fdf, curr);
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
	t_fdf	*fdf;

	fdf = init_fdf(map);
	push_map(fdf);
	ft_drow_menu(*fdf);
	ft_controls(fdf);
	mlx_loop(fdf->mlx);
	return;
}