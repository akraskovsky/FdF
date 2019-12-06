/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:06:17 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/06 18:41:34 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    push_stack(t_point *newpoint, t_point **points_stack)
{
	if (points_stack && newpoint)
	{
		newpoint->next = *points_stack;
		*points_stack = newpoint;
	}
	return ;
}

t_point	*pop_stack(t_point **points_stack)
{
	t_point	*point;

	point = NULL;
	if (points_stack && *points_stack)
	{
		point = *points_stack;
		*points_stack = (*points_stack)->next;
	}
	return (point);
}

void	create_map_array(t_map	*map, t_point **points_stack)
{
	int		num;
	t_point	*point;
	
	num = map->size_x * map->size_y;
	if (!(map->z = (int *)malloc(sizeof(int) * num)))
		terminate("Memory allocation error");
	if (!(map->color = (int *)malloc(sizeof(int) * num)))
		terminate("Memory allocation error");
	while (num > 0)
	{
		point = pop_stack(points_stack);
		num--;
		map->z[num] = point->z;
		map->color[num] = point->color;
		if (point->z > map->max_z)
			map->max_z = point->z;
		if (point->z < map->min_z)
			map->min_z = point->z;
		free(point);
	}
	return ;
}