/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:59:39 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/21 14:18:09 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

char    *fdf_read_map(int fd)
{
	char	*line;
	size_t	n;
	
	line = (char *)malloc(11);
//	n = read(fd, line, 10);
	n = get_next_line(fd, &line);
	printf("fd=%d, n=%zu\n", fd, n);
	printf("line: \'%s\'\n", line);
//	ft_putstr(*line);
//	ft_putstr("\n");
	return (line);
}