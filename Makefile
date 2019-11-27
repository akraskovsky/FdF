# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 10:53:01 by fprovolo          #+#    #+#              #
#    Updated: 2019/11/27 18:49:19 by fprovolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./
SRC_NAME = main.c read_map.c clean_tools.c test_tools.c draw_map.c

OBJ_PATH = ./
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a

MLX_PATH = ./minilibx_macos/
MLX = $(MLX_PATH)libmlx.a

LIBRARIES = -lmlx -lft -L$(LIBFT_PATH) -L$(MLX_PATH) -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_NAME)
	$(CC) -o $(NAME) $(OBJ_NAME) $(LIBRARIES)

%.o: %.c $(NAME).h
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT): 
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIBFT)
	/bin/rm -f $(MLX)

re: fcleean all
