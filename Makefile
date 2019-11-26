# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 10:53:01 by fprovolo          #+#    #+#              #
#    Updated: 2019/11/26 16:24:27 by fprovolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./
SRC_NAME = main.c read_map.c clean_tools.c

OBJ_PATH = ./
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

LIB_PATH = libft/
LIB_NAME = libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB_PATH)$(LIB_NAME) $(OBJ_NAME)
	$(CC) -o $(NAME) $(OBJ_NAME) -L $(LIB_PATH) -lft

%.o: %.c $(NAME).h
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIB_PATH)$(LIB_NAME): 
	make -C $(LIB_PATH)

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIB_PATH) clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIB_PATH)$(LIB_NAME)

re: fcleean all