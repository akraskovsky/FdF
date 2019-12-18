/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:18:15 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/18 15:09:06 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_map(t_map *map, t_fdf *fdf)
{
	free(map->z);
	free(map->color);
	free(map);
	free(fdf->mouse);
	free(fdf);
	return ;
}

void	clean_points(char **points)
{
	int	i;

	i = 0;
	while (points[i] != NULL)
	{
		free(points[i]);
		i++;
	}
	free(points);
	return ;
}

void	terminate(char *message)
{
	ft_putendl(message);
	exit(1);
}
