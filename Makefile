# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 10:53:01 by fprovolo          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2019/12/11 19:26:24 by fprovolo         ###   ########.fr        #
=======
#    Updated: 2019/12/11 17:42:06 by jmalik           ###   ########.fr        #
>>>>>>> 540a6e02cfd6f57962247cbd1b8582808eabab91
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./
SRC_NAME = main.c read_map.c clean_tools.c test_tools.c draw_map.c tools.c \
<<<<<<< HEAD
			stack.c init_fdf.c

=======
			stack.c ft_drow_menu.c
>>>>>>> 540a6e02cfd6f57962247cbd1b8582808eabab91
OBJ_PATH = ./objects/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a

MLX_PATH = ./minilibx_macos/
MLX = $(MLX_PATH)libmlx.a

LIBRARIES = -lmlx -lft -L$(LIBFT_PATH) -L$(MLX_PATH) -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_PATH) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBRARIES)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: %.c $(NAME).h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): 
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

clean:
	/bin/rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIBFT)
	/bin/rm -f $(MLX)

re: fcleean all
