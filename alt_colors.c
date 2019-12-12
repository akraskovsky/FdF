/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:08:49 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/12 20:19:36 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_alt_color(t_map *map, int z)
{
	double	delta;
	double	pcnt;
	int		red;
	int		green;
	int		blue;

	if ((delta = map->max_z * map->scale_z - map->min_z * map->scale_z) <= 0)
		return(map->bottom_color);
	pcnt = (z - map->min_z * map->scale_z) / delta;
	red = (map->bottom_color >> 16 & 0xFF) + ((map->top_color >> 16 & 0xFF) - (map->bottom_color >> 16 & 0xFF)) * pcnt;
	green = (map->bottom_color >> 8 & 0xFF) + ((map->top_color >> 8 & 0xFF) - (map->bottom_color >> 8 & 0xFF)) * pcnt;
	blue = (map->bottom_color & 0xFF) + ((map->top_color & 0xFF) - (map->bottom_color & 0xFF)) * pcnt;
	printf("z=%d\tdelta=%f\tpcnt=%f\tcolor=%6X\n", z, delta, pcnt, (red << 16) + (green << 8) + blue);
	return ((red << 16) + (green << 8) + blue);
}