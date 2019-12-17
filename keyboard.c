/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 10:51:14 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/17 18:39:28 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	made_key_move(int key, t_fdf *fdf)
{
	if (key == 126)
		fdf->map->shift_y -= 10;
	if (key == 125)
		fdf->map->shift_y += 10;
	if (key == 124)
		fdf->map->shift_x += 10;
	if (key == 123)
		fdf->map->shift_x -= 10;
	if (key == 24 || key == 69)
	{
		fdf->map->scale_xy += 2;
		fdf->map->scale_z += 1;
	}
	if (key == 27 || key == 78)
	{
		if (fdf->map->scale_xy > 2)
			fdf->map->scale_xy -= 2;
		if (fdf->map->scale_z > 1)
			fdf->map->scale_z -= 1;
	}
	if (key == 84 || key == 19)
		fdf->map->scale_z -= 2;
	if (key == 91 || key == 28)
		fdf->map->scale_z += 2;
}

void	made_key_rotate2(int key, t_fdf *fdf)
{
	if (key == 89 || key == 26)
		fdf->map->angle_x += 0.05;
	if (key == 92 || key == 25)
		fdf->map->angle_x -= 0.05;
	if (key == 86 || key == 21)
		fdf->map->angle_y += 0.05;
	if (key == 88 || key == 22)
		fdf->map->angle_y -= 0.05;
	if (key == 83 || key == 18)
		fdf->map->angle_z += 0.05;
	if (key == 85 || key == 20)
		fdf->map->angle_z -= 0.05;
}

void	made_key_rotate(int key, t_fdf *fdf)
{
	if (key == 49)
	{
		if (fdf->map->angle_x != 0.0)
		{
			fdf->map->angle_x = 0.0;
			fdf->map->angle_y = 0.0;
			fdf->map->angle_z = 0.0;
		}
		else
		{
			fdf->map->angle_x = -0.523599;
			fdf->map->angle_y = 0.523599;
			fdf->map->angle_z = -0.523599;
		}
	}
	made_key_rotate2(key, fdf);
}

void	made_key_colors(int key, t_fdf *fdf)
{
	if (key == 257 || key == 258)
	{
		if (fdf->map->alt_col == 0)
		{
			fdf->map->alt_col = 1;
			fdf->map->top_color = UP_COLOR2;
			fdf->map->bottom_color = DOWN_COLOR2;
		}
		else if (fdf->map->alt_col == 1)
		{
			fdf->map->alt_col = 2;
			fdf->map->top_color = UP_COLOR;
			fdf->map->bottom_color = DOWN_COLOR;
		}
		else
			fdf->map->alt_col = 0;
	}
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, fdf);
}

int		key_pressed(int key, t_fdf *fdf)
{
	made_key_move(key, fdf);
	made_key_rotate(key, fdf);
	made_key_colors(key, fdf);
	if (key == 53)
	{
		mlx_destroy_image(fdf->mlx, fdf->img_ptr);
		exit(0);
	}
	push_map(fdf);
	return (0);
}
