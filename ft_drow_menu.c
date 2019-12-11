/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drow_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:31:00 by jmalik            #+#    #+#             */
/*   Updated: 2019/12/11 17:39:27 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_drow_menu(t_fdf p)
{
    char    *menu;

    menu = "up, down, left, right: move picture";
	mlx_string_put(p.mlx, p.win, 10, 5, 0x03fc35, menu);
	menu = "5, spase: 3d/2d mode; +, -: zoom";
	mlx_string_put(p.mlx, p.win, 10, 20, 0x03fc35, menu);
	menu = "8, 2: z-scale; 4, 6: rotation";
	mlx_string_put(p.mlx, p.win, 10, 35, 0x03fc35, menu);
	menu = "f: full screen mode";
	mlx_string_put(p.mlx, p.win, 10, 50, 0x03fc35, menu);
}