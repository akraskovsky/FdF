# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 15:52:55 by fprovolo          #+#    #+#              #
#    Updated: 2019/11/20 15:05:33 by fprovolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNCTIONS = ft_memset\
			ft_bzero\
			ft_memcpy\
			ft_memccpy\
			ft_memmove\
			ft_memchr\
			ft_memcmp\
			ft_strlen\
			ft_strdup\
			ft_strcpy\
			ft_strncpy\
			ft_strcat\
			ft_strncat\
			ft_strlcat\
			ft_strchr\
			ft_strrchr\
			ft_strcmp\
			ft_strncmp\
			ft_strstr\
			ft_strnstr\
			ft_isalpha\
			ft_isdigit\
			ft_isalnum\
			ft_isascii\
			ft_isprint\
			ft_toupper\
			ft_tolower\
			ft_atoi\
			ft_memalloc\
			ft_memdel\
			ft_strnew\
			ft_strdel\
			ft_strclr\
			ft_striter\
			ft_striteri\
			ft_strmap\
			ft_strmapi\
			ft_strequ\
			ft_strnequ\
			ft_strsub\
			ft_strjoin\
			ft_strtrim\
			ft_strsplit\
			ft_itoa\
			ft_putchar\
			ft_putstr\
			ft_putendl\
			ft_putnbr\
			ft_putchar_fd\
			ft_putstr_fd\
			ft_putendl_fd\
			ft_putnbr_fd\
			ft_lstnew\
			ft_lstdelone\
			ft_lstdel\
			ft_lstadd\
			ft_lstiter\
			ft_lstmap\
			get_next_line\

SRC = $(patsubst %,%.c,$(FUNCTIONS))
OBJ = $(patsubst %,%.o,$(FUNCTIONS))
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c $(NAME).h
		gcc $(CFLAGS) -I -o $@ -c $<

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all
