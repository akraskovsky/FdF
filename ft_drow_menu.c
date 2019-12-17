/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drow_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:31:00 by jmalik            #+#    #+#             */
/*   Updated: 2019/12/17 18:23:37 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drow_menu(t_fdf p)
{
	char	*menu;

	menu = "Move picture: ";
	mlx_string_put(p.mlx, p.win, 15, 10, MENU_LETTERS, menu);
	menu = "  - Arrows  Up, Down, Left, Right";
	mlx_string_put(p.mlx, p.win, 15, 32, MENU_LETTERS, menu);
	menu = "  - or Mouse with the left button";
	mlx_string_put(p.mlx, p.win, 15, 54, MENU_LETTERS, menu);
	menu = "Rotate:";
	mlx_string_put(p.mlx, p.win, 15, 76, MENU_LETTERS, menu);
	menu = "  - by X:   7, 9";
	mlx_string_put(p.mlx, p.win, 15, 98, MENU_LETTERS, menu);
	menu = "  - by y:   4, 6 or Mouse right button";
	mlx_string_put(p.mlx, p.win, 15, 120, MENU_LETTERS, menu);
	menu = "  - by Z:   1, 3";
	mlx_string_put(p.mlx, p.win, 15, 142, MENU_LETTERS, menu);
	menu = "Zoom:       +, -";
	mlx_string_put(p.mlx, p.win, 15, 164, MENU_LETTERS, menu);
	menu = "            or Mouse scroll";
	mlx_string_put(p.mlx, p.win, 15, 186, MENU_LETTERS, menu);
	menu = "Z-scale:    8, 2";
	mlx_string_put(p.mlx, p.win, 15, 208, MENU_LETTERS, menu);
	ft_drow_menu2(p);
}

void	ft_drow_menu2(t_fdf p)
{
	char	*menu;

	menu = "2d/3d mode: Spase";
	mlx_string_put(p.mlx, p.win, 15, 230, MENU_LETTERS, menu);
	menu = "Change color: Shift";
	mlx_string_put(p.mlx, p.win, 15, 252, MENU_LETTERS, menu);
	menu = "            or Mouse middle button";
	mlx_string_put(p.mlx, p.win, 15, 274, MENU_LETTERS, menu);
	menu = "Window size:";
	mlx_string_put(p.mlx, p.win, 15, 296, MENU_LETTERS, menu);
	menu = "  Reduce:   A, Z";
	mlx_string_put(p.mlx, p.win, 15, 318, MENU_LETTERS, menu);
	menu = "  Expand:   S, X";
	mlx_string_put(p.mlx, p.win, 15, 340, MENU_LETTERS, menu);
	menu = "Full screen: F";
	mlx_string_put(p.mlx, p.win, 15, 362, MENU_LETTERS, menu);
}
