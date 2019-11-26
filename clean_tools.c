/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:18:15 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/26 18:23:37 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_map(t_map *map)
{
	t_pix	*tmp;
	
	while (map->pix != NULL)
	{
		tmp = map->pix;
		map->pix = map->pix->next;
		free(tmp);
	}
	free(map);
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