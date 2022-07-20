# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 10:46:35 by nrenz             #+#    #+#              #
#    Updated: 2022/07/13 12:14:16 by nrenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	so_long.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx -c $< -o $@ -I ../libft

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

libft:
	make all -C ../libft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

leaks:
	make
	leaks --atExit -- ./so_lomg

.PHONY: all clean fclean re leaks