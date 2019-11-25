/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:59:39 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/25 19:57:49 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_map	*read_map(int fd)
{
	char	*line;
	int		res;
	int		parse;
	t_map	*map;
	
	if (!(map = init_map()))
		return (NULL);
	parse = 1;
	while ((res = get_next_line(fd, &line)) > 0 && parse == 1)
	{
		parse = parse_line(line, map);
		free(line);
	}
	if (res == 0 && parse == 1)
	{
		free(line);
		return (map);
	}
	return (NULL);
}