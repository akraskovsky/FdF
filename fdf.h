/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:40:42 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/11 18:22:46 by jmalik           ###   ########.fr       */
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

typedef struct		s_point
{
	int				z;
	int				color;
	struct s_point	*next;
}					t_point;

typedef struct		s_map
{
	int				size_x;
	int				size_y;
	int				max_z;
	int				min_z;
	int				scale_xy;
	int				scale_z;
	int				shift_x;
	int				shift_y;
	int				center_x;
	int				center_y;
	int				*z;
	int				*color;
	double			angle;
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
void				parse_point(char *line, t_point **points_stack);
void				parse_line(char *line, t_point **stack, t_map *map);
void				clean_map(t_map *map);
void				clean_points(char **points);
void				print_map(t_map *map);
void				draw_map(t_map *map);
int					key_pressed(int key, t_fdf *fdf);
int					ft_abs(int x);
double  			percent(t_pix start, t_pix finish, t_pix point);
void				terminate(char *message);
void    			push_stack(t_point *newpoint, t_point **points_stack);
t_point				*pop_stack(t_point **points_stack);
void				create_map_array(t_map	*map, t_point **points_stack);
t_pix				get_point(t_map *map, int x, int y);
void				push_map(t_fdf *fdf);
t_pix				iso(t_pix pix, t_fdf *fdf);
void 				draw_line(t_fdf *fdf, t_pix start, t_pix end);
void    			ft_drow_menu(t_fdf p);

#endif