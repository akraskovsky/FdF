/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:23:50 by jmalik            #+#    #+#             */
/*   Updated: 2019/12/12 19:03:53 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_win_size(int key, t_fdf *fdf)
{
	if ((key == 0 && fdf->map->win_y <= 200) || (key == 6 && fdf->map->win_x <= 200))
		return (1);
	if ((key == 1 && fdf->map->win_y >= 1400) || (key == 7 && fdf->map->win_x >= 2560))
		return (1);
	return (0);
}

void	full_screen(t_fdf *fdf)
{
	static int old_x;
	static int old_y;

	if (fdf->map->win_x != 2560)
	{
		old_x = fdf->map->win_x;
		old_y = fdf->map->win_y;
	}
	fdf->map->win_x = (fdf->map->win_x == 2560) ? old_x : 2560;
	fdf->map->win_y = (fdf->map->win_y == 1400) ? old_y : 1400;
}

void	change_window_size(int key, t_fdf *fdf)
{
	if (check_win_size(key, fdf))
		return ;
	if (key == 6)
		fdf->map->win_x -= 100;
	if (key == 7)
		fdf->map->win_x += 100;
	if (key == 0)
		fdf->map->win_y -= 100;
	if (key == 1)
		fdf->map->win_y += 100;
	if (key == 3)
		full_screen(fdf);
}

void	new_window(int key, t_fdf *fdf)
{
	change_window_size(key, fdf);
	mlx_destroy_window(fdf->mlx, fdf->win);
//	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->map->win_x, fdf->map->win_y, "FdF project");
	if (!(fdf->img_ptr = mlx_new_image(fdf->mlx, fdf->map->win_x, fdf->map->win_y)))
		terminate("Initialization error");
	if (!(fdf->image = mlx_get_data_addr(fdf->img_ptr, &fdf->bits_per_pixel, &fdf->size_line, &fdf->endian)))
		terminate("Initialization error");
	push_map(fdf);
//	ft_drow_menu(*fdf);
	mlx_key_hook(fdf->win, key_pressed, fdf);
	mlx_loop(fdf->mlx);
}