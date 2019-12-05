/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:40:42 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/05 18:13:58 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"

# define HEIGHT		1080
# define WIDTH		1920
# define DEF_COLOR	0xFFFFFF
# define BG_COLOR	0x000000
# define MENU_COLOR	0x0F0F0F

typedef struct		s_pix
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_pix	*next;
}					t_pix;

typedef struct		s_map
{
	int				size_x;
	int				size_y;
	int				max_z;
	int				min_z;
	int				*z_array;
	int				*color_array;
	t_pix			*pix;
	t_pix			*last_pix;
}					t_map;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	t_map			*map;
}					t_fdf;

t_map				*read_map(int fd);
t_map				*init_map(void);
int					parse_color(char *str);
void				parse_point(char *line, t_map *map, int x, int y);
void				parse_line(char *line, t_map *map);
void				clean_map(t_map *map);
void				clean_points(char **points);
void				print_map(t_map *map);
void				draw_map(t_map *map);
int					key_pressed(int key, void *param);
int					ft_abs(int x);
double  			percent(t_pix start, t_pix finish, t_pix point);
void				terminate(char *message);

#endif