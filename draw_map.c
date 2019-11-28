/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:25:31 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/28 18:48:57 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *fdf, t_pix start, t_pix end)
{
	int	delta_x;
	int	delta_y;
	int sign_x;
	int	sign_y;
	int	error1;
	int	error2;

	delta_x = ft_abs(end.x - start.x);
	delta_y = ft_abs(end.y - start.y);
	sign_x = (start.x < end.x) ? 1 : -1;
	sign_y = (start.y < end.y) ? 1 : -1;
	error1 = delta_x - delta_y;
	mlx_pixel_put(fdf->mlx, fdf->win, end.x, end.y, 0xFFFFFF);
	while (start.x != end.x || start.y != end.y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, start.x, start.y, 0xFF0000);
		error2 = error1 * 2;
		if (error2 > -delta_y)
		{
			error1 -= delta_y;
			start.x += sign_x;
		}
		if (error2 < delta_x)
		{
			error1 += delta_x;
			start.y += sign_y;
		}
	}
	return ;
}

void	draw_map(t_map *map)
{
	t_fdf	*fdf;
	t_pix	start;
	t_pix	end;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		terminate("Initialization error");
	if (!(fdf->mlx = mlx_init()))
		terminate("Initialization error");
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF project")))
		terminate("Initialization error");
	fdf->map = map;
	mlx_pixel_put(fdf->mlx, fdf->win, 50, 50, 0xFFFF);
	
	start.x = 55;
	start.y = 55;
	start.color = 0xFF0000;
	end.x = 1000;
	end.y = 255;
	end.color = 0xFFFFFF;
	draw_line(fdf, start, end);
	mlx_key_hook(fdf->win, key_pressed, (void *)0);
	mlx_loop(fdf->mlx);
	return ;
}