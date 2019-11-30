/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 10:51:14 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/29 13:46:25 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_map(t_map *map)
{
	t_pix   *ptr;

	printf("field x=%d y=%d, color=%X\n", map->size_x, map->size_y, map->bg_color);
	ptr = map->pix;
	while (ptr != NULL)
	{
		printf("x=%d\ty=%d\tz=%d\tcolor=%X\n", ptr->x, ptr->y, ptr->z, ptr->color);
		ptr = ptr->next;
	}
}

int		key_pressed(int key, void *param)
{
	void	*dummy;
	
	dummy = param;
	ft_putnbr(key);
	ft_putendl(" was pressed");
	if (key == 53)
		exit(0);
	return (0);
}