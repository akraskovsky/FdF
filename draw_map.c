/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:25:31 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/02 17:39:52 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color(t_pix start, t_pix end, t_pix curr)
{
	int		red;
	int		green;
	int		blue;
	double	pcnt;

	pcnt = percent(start, end, curr);
	red = (start.color >> 16 & 0xFF) + ((end.color >> 16 & 0xFF)
			- (start.color >> 16 & 0xFF)) * pcnt;
	green = (start.color >> 8 & 0xFF) + ((end.color >> 8 & 0xFF)
			- (start.color >> 8 & 0xFF)) * pcnt;
	blue = (start.color & 0xFF) + ((end.color & 0xFF) 
			- (start.color & 0xFF)) * pcnt;
//	printf("percent=%f\tred=%X green=%X blue=%X\n", pcnt, red, green, blue);
	return ((red << 16) + (green << 8) + blue);
}

void	draw_line(t_fdf *fdf, t_pix start, t_pix end)
{
	t_pix	delta;
	t_pix	sign;
	t_pix	curr;
	int	error[2];

	delta.x = ft_abs(end.x - start.x);
	delta.y = ft_abs(end.y - start.y);
	sign.x = (start.x < end.x) ? 1 : -1;
	sign.y = (start.y < end.y) ? 1 : -1;
	error[0] = delta.x - delta.y;
	mlx_pixel_put(fdf->mlx, fdf->win, end.x, end.y, end.color);
	curr = start;
	while (curr.x != end.x || curr.y != end.y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, curr.x, curr.y, color(start, end, curr));
//		mlx_pixel_put(fdf->mlx, fdf->win, curr.x, curr.y, 0xFFFF00);
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
		
	start.x = 55;
	start.y = 355;
	start.color = 0xFF0000;
	end.x = 1000;
	end.y = 300;
	end.color = 0x00FF00;
	draw_line(fdf, start, end);
	mlx_key_hook(fdf->win, key_pressed, (void *)0);
	mlx_loop(fdf->mlx);
	return ;
}