# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 10:46:35 by nrenz             #+#    #+#              #
#    Updated: 2022/10/13 14:53:57 by nrenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	so_long.c \
		get_map.c \
		map_error_check.c \
		map_error_check2.c \
		map_error_check3.c \
		player_path_check.c \
		map_img.c \
		moves.c \

OBJS = $(SRCS:.c=.o)

LIBFTDIR = libft
LIBFT = ./libft/libft.a

MLXDIR = mlx
MLX = ./mlx/libmlx.a


CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft

NAME = so_long

all: libft $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $^ -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	make all -C $(LIBFTDIR)

$(MLX):
	make all -C $(MLXDIR)

clean:
	make clean -C libft
	make clean -C mlx
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re