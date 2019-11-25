/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:19:37 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/25 19:57:49 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*parse_line(char *line, t_map *map)
{
		int 	column;
		char	**splits;

		splits = ft_strsplit(line, ' ');
		if (splits == NULL)
			return (-1);
		column = 0;
		while (splits[column] != NULL)
		{
			ft_putendl(splits[column]);
			

			
			if (NULL == parse_point(splits[column], map))
				return (NULL);
			column++;
		}
		if (map->size_x == 0 && column !)

	return (0);
}