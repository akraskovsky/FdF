/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:30:58 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/17 18:35:36 by fprovolo         ###   ########.fr       */
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
