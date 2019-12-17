/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:23:21 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/17 15:47:27 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

t_pix	iso(t_pix pix, t_fdf *fdf)
{
	double	x;
	double	y;

	y = pix.y;
	pix.y = y * cos(fdf->map->angle_x) + pix.z * sin(fdf->map->angle_x);
	pix.z = -y * sin(fdf->map->angle_x) + pix.z * cos(fdf->map->angle_x);
	x = pix.x;
	pix.x = x * cos(fdf->map->angle_y) + pix.z * sin(fdf->map->angle_y);
	pix.z = -x * sin(fdf->map->angle_y) + pix.z * cos(fdf->map->angle_y);
	x = pix.x;
	pix.x = x * cos(fdf->map->angle_z) - pix.y * sin(fdf->map->angle_z);
	pix.y = x * sin(fdf->map->angle_z) + pix.y * cos(fdf->map->angle_z);
	return (pix);
}

void	push_map(t_fdf *fdf)
{
	int x;
	int	y;

	fill_background(fdf);
	y = 0;
	while (y < fdf->map->size_y)
	{
		x = 0;
		while (x < fdf->map->size_x)
		{
			if (x < fdf->map->size_x - 1)
				draw_line(fdf, iso(get_point(fdf->map, x, y), fdf), iso(get_point(fdf->map, x + 1, y), fdf));
			if (y < fdf->map->size_y - 1)	
				draw_line(fdf, iso(get_point(fdf->map, x, y), fdf), iso(get_point(fdf->map, x, y + 1), fdf));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_ptr, 0, 0);
	ft_drow_menu(*fdf);
}

double  percent(t_pix start, t_pix finish, t_pix point)
{
	double	len;
	double	current;

	if (ft_abs(finish.x - start.x) > ft_abs(finish.y - start.y))
	{
		len = finish.x - start.x;
		current = point.x - start.x;
	}
	else
	{
		len = finish.y - start.y;
		current = point.y - start.y;
	}
	return ((len == 0) ? 1.0 : (current / len));
}

int		ft_abs(int x)
{
	return ((x < 0) ? -x : x);
}