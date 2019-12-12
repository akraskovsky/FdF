/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:59:39 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/12 18:10:39 by jmalik           ###   ########.fr       */
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
	map->scale_xy = 1;
	map->scale_z = 1;
	map->win_x = WIDTH;
	map->win_y = HEIGHT;
	map->center_x = map->win_x / 2;
	map->center_y = map->win_y / 2;
	map->shift_y = 0;
	map->shift_x = 0;
	map->angle = 0.523599;
	map->z = NULL;
	map->color = NULL;
	return (map);
}

int		parse_color(char *str)
{
	int	color;
	
	if (ft_strncmp(str, "0x", 2) != 0)
		terminate("Error: Bad map");
	str += 2;
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

void	parse_point(char *line, t_point **points_stack)
{
	t_pix	*pix;
	t_point	*newpoint;

	if (!(pix = (t_pix *)malloc(sizeof(t_pix))))
		terminate("Memory allocation error");
	if (!(newpoint = (t_point *)malloc(sizeof(t_point))))
		terminate("Memory allocation error");
	newpoint->z = ft_atoi(line);
	newpoint->color = DEF_COLOR;
	while (*line != '\0' && *line != ',')
		line++;
	if (*line == ',')
		newpoint->color = parse_color(line + 1);
	push_stack(newpoint, points_stack); 	
	return ;
}

void	parse_line(char *line, t_point **points_stack, t_map *map)
{
	int		column;
	char	**points;

	if (!(points = ft_strsplit(line, ' ')))
		terminate("error: Bad map");
	column = 0;
	while (points[column] != NULL)
	{
		parse_point(points[column], points_stack);
		column++;
	}
	if (map->size_x == 0)			// 1st string
		map->size_x = column;
	if (map->size_x != column)		// String length differs
		terminate("error: Bad map");
	clean_points(points);
	return ;
}

t_map	*read_map(int fd)
{
	char	*line;
	int		string;
	t_map	*map;
	t_point	*points_stack;
	
	map = init_map();
	points_stack = NULL;
	string = 1;
	while (string > 0)
	{
		if ((string = get_next_line(fd, &line)) < 0)
			terminate("File error");
		else if (string > 0)
			parse_line(line, &points_stack, map);
		free(line);
		map->size_y += string;
	}
	create_map_array(map, &points_stack);
	map->scale_xy = HEIGHT / (map->size_x + map->size_y) * 3 / 2;
	if (map->max_z > map->min_z)
		map->scale_z = HEIGHT / 4 / (map->max_z - map->min_z);

	return (map);
}
