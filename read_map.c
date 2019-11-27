/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:59:39 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/27 11:09:38 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->size_x = 0;
	map->size_y = 0;
	map->min_z = 0;
	map->max_z = 0;
	map->bg_color = 0x000000;
	map->pix = NULL;
	map->last_pix = NULL;
	return (map);
}

int		parse_point(char *line, t_map *map, int x, int y)
{
	char	*ptr;
	t_pix	*pix;

	ptr = line;
	while (*ptr != '\0')
	{
		if (!(ft_strchr("+-0123456789", (int)*ptr)))
			return (-1);
		ptr++;
	}
	if (!(pix = (t_pix *)malloc(sizeof(t_pix))))
		return (-1);
	pix->x = x;
	pix->y = y;
	pix->z = atoi(line);
	pix->color = 0x00FFFF;
	pix->next = NULL;
	if (map->pix == NULL)
		map->pix = pix;
	else
		map->last_pix->next = pix;
	map->last_pix = pix;
	return (0);
}

int		parse_line(char *line, t_map *map)
{
	int		column;
	int		ret;
	char	**points;

	points = ft_strsplit(line, ' ');
	if (points == NULL)
		return (-1);
	column = 0;
	ret = 0;
	while (points[column] != NULL && ret >= 0)
	{
		if (0 > parse_point(points[column], map, column, map->size_y))
			ret = -1;
		column++;
	}
	if (map->size_x == 0)
		map->size_x = column;
	if (map->size_x != column)
		ret = -1;
	clean_points(points);
	return (ret);
}

t_map	*read_map(int fd)
{
	char	*line;
	int		res;
	t_map	*map;
	
	if (!(map = init_map()))
		return (NULL);
	res = 1;
	while (res > 0)
	{
		if ((res = get_next_line(fd, &line)) > 0)
			if (0 > parse_line(line, map))
			{
				free(line);
				clean_map(map);
				return (NULL);
			}
		if (res < 0)
			return (NULL);
		free(line);
		map->size_y += res;
		// printf("Read_map, line=%d\n", map->size_y);
	}
	return (map);
}
