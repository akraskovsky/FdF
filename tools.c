/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:23:21 by fprovolo          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/12/11 22:57:32 by fprovolo         ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2019/12/11 18:25:10 by jmalik           ###   ########.fr       */
=======
/*   Updated: 2019/12/11 17:26:26 by fprovolo         ###   ########.fr       */
>>>>>>> 0db513214b6783065418c20613c9d6df133fcea2
>>>>>>> 540a6e02cfd6f57962247cbd1b8582808eabab91
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
}

double  percent(t_pix start, t_pix finish, t_pix point)
{
	double	len;
	double	current;

	if (abs(finish.x - start.x) > abs(finish.y - start.y))
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