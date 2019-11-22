/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:59:39 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/22 19:28:41 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

char    *fdf_read_map(int fd)
{
	char	*line;
	char	**splits;
	int		n;
	
	n = 0;
	while ((n = get_next_line(fd, &line)) > 0)
	{
		splits = ft_strsplit(line, ' ');
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
	}
	if (n == 0)
		free(line);
	return (NULL);
}