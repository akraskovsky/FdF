/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:48:14 by jmalik            #+#    #+#             */
/*   Updated: 2019/12/14 18:59:28 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_controls(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_pressed, fdf);
	mlx_hook(fdf->win, 4, 0, ft_press_mouse, fdf);
	mlx_hook(fdf->win, 5, 0, ft_mouse_release, fdf);
	mlx_hook(fdf->win, 6, 0, ft_mmouse, fdf);
}

void	ft_scale(int key, t_fdf *fdf)
{
	if (key == MOUSE_SCROLL_UP)
    {
			fdf->map->scale_xy += 2;
			fdf->map->scale_z += 1;
	}
	else if (key == MOUSE_SCROLL_DOWN)
	{
			if (fdf->map->scale_xy > 2)
				fdf->map->scale_xy -= 2;
			if (fdf->map->scale_z >1)
				fdf->map->scale_z -= 1;
	}
	push_map(fdf);
}

void	ft_rot_col(int key, t_fdf *fdf)
{
	if (key == MOUSE_M_BUT)
	{
		if (fdf->map->alt_col == 0)
			fdf->map->alt_col = 1;
		else
			fdf->map->alt_col = 0;
	}
	if (key == MOUSE_R_BUT)
		fdf->map->angle += 0.4;
	push_map(fdf);
}

int			ft_press_mouse(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		ft_scale(button, fdf);
	else if (button == MOUSE_R_BUT)
		ft_rot_col(button, fdf);
	else if (button == MOUSE_M_BUT)
		ft_rot_col(button, fdf);
	else if (button == MOUSE_L_BUT)
		fdf->mouse->is_pressed = true;
	return (0);
}

int			ft_mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->is_pressed = false;
	return (0);
}

int			ft_mmouse(int x, int y, void *param)
{
	t_fdf	*fdf;
       
	fdf = (t_fdf *)param;
	fdf->mouse->previous_x = fdf->mouse->x;
	fdf->mouse->previous_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed)
	{
		fdf->map->shift_x += (x - fdf->mouse->previous_x);
		fdf->map->shift_y += (y - fdf->mouse->previous_y);
		push_map(fdf);
	}
	return (0);
}