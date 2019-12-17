/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:40:42 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/17 14:40:37 by fprovolo         ###   ########.fr       */
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

# define HEIGHT			1400
# define WIDTH			2560
# define DEF_COLOR		0x00AAAA
# define BG_COLOR		0x000022
# define MENU_COLOR		0x0F0F0F
# define UP_COLOR		0xFFFFFF
# define DOWN_COLOR		0x000022
# define UP_COLOR2		0xFFFF22
# define DOWN_COLOR2	0x004444
# define MENU_W			420
# define MENU_H			280
# define MOUSE_L_BUT	1
# define MOUSE_R_BUT	2
# define MOUSE_M_BUT	3
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

typedef enum
{
	false,
	true
}	t_bool;

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
	int				top_color;
	int				bottom_color;
	unsigned char	alt_col;
	int				*z;
	int				*color;
	int				win_x;
	int				win_y;
	double			angle;
}					t_map;

typedef  struct 	s_mouse
{
	char 			is_pressed;
	int 			x;
	int 			y;
	int 			previous_x;
	int 			previous_y;
} 					t_mouse;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*image;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	t_mouse			*mouse;
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
t_fdf				*init_fdf(t_map *map);
void				test_of_colors(t_fdf *fdf);
void				pixel_to_image(t_fdf *fdf, t_pix pix);
void				fill_background(t_fdf *fdf);
void    			ft_drow_menu(t_fdf p);
void				new_window(int key, t_fdf *fdf);
int					get_alt_color(t_map *map, int z);
void				ft_controls(t_fdf *fdf);
int					ft_press_mouse(int button, int x, int y, void *param);
int					ft_mouse_release(int button, int x, int y, void *param);
int					ft_mmouse(int x, int y, void *param);
void				ft_scale(int key, t_fdf *fdf);

#endif