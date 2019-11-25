/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:40:42 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/25 19:07:24 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct  s_pix
{
	int			x;
	int			y;
	int			z;
	int			red;
	int			green;
	int			blue;
	int			color;
	t_pix		*next;
}				t_pix;

typedef struct	s_map
{
	int			size_x;
	int			size_y;
	int			max_z;
	int			min_z;
	t_pix		*pix;
}				t_map;

t_map			*read_map(int fd);

#endif