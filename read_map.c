/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:59:39 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/05 18:27:53 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		terminate("Memory allocation error");
	map->size_x = 0;
	map->size_y = 0;
	map->min_z = 0;
	map->max_z = 0;
	map->z_array = NULL;
	map->color_array = NULL;
	map->pix = NULL;
	map->last_pix = NULL;
	return (map);
}

int		parse_color(char *str)
{
	int	color;
	
	printf("str = %s\n", str);
	if (ft_strncmp(str, ",0x", 3) != 0)
		terminate("Error: Bad map");
	str += 3;
	color = 0;
	while (*str != '\0')
	{
		if (ft_strchr("abcdefABCDEF", *str))
			color = color * 16 + (ft_toupper(*str) - 55);
		else if (ft_strchr("0123456789", *str))
			color = color * 16 + (*str - 48);
		else
			terminate("error: Bad map");
		str++;
	}
	return (color);
}

void	parse_point(char *line, t_map *map, int x, int y)
{
	t_pix	*pix;

	if (!(pix = (t_pix *)malloc(sizeof(t_pix))))
		terminate("Memory allocation error");
	pix->x = x;
	pix->y = y;
	pix->z = ft_atoi(line);
	pix->color = DEF_COLOR;
	pix->next = NULL;
	if (map->pix == NULL)
		map->pix = pix;
	else
		map->last_pix->next = pix;
	map->last_pix = pix;
	while (*line != '\0')
	{
		if (!(ft_strchr("+-0123456789", (int)*line)))
		{
			pix->color = parse_color(line);
			return ;
		}
		line++;
	}
	return ;
}

void	parse_line(char *line, t_map *map)
{
	int		column;
	char	**points;

	if (!(points = ft_strsplit(line, ' ')))
		terminate("error: Bad map");
	column = 0;
	while (points[column] != NULL)
	{
		parse_point(points[column], map, column, map->size_y);
		column++;
	}
	if (map->size_x == 0)
		map->size_x = column;
	if (map->size_x != column)
		terminate("error: Bad map");
	clean_points(points);
	return ;
}

t_map	*read_map(int fd)
{
	char	*line;
	int		res;
	t_map	*map;
	
	map = init_map();
	res = 1;
	while (res > 0)
	{
		if ((res = get_next_line(fd, &line)) < 0)
			terminate("File error");
		else if (res > 0)
			parse_line(line, map);
		free(line);
		map->size_y += res;
	}
	return (map);
}
