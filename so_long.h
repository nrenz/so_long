/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:33:05 by nrenz             #+#    #+#             */
/*   Updated: 2022/10/13 15:25:10 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

# define BLOCK 64
# define WALL "./data/wall.xpm"
# define GROUND "./data/ground.xpm"
# define PLAYER "./data/dino.xpm"
# define COLLECT "./data/collect.xpm"
# define EXIT "./data/exit.xpm"
# define OPEN "./data/open.xpm"
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ESC 53

/* 	t_data object to store variables
	to pass multiple arguments the struct is needed
	in order to pass a pointer to the struct
*/
typedef struct s_solong
{
	char	**map;
	int		map_width;
	int		map_height;
	void	*mlx;
	void	*mlx_window;
	int		steps;
	int		score;
	int		p;
	int		e;
	int		c;
	int		x_pos;
	int		y_pos;
	int		size_x;
	int		size_y;
	char	last_pos;
	void	*player;
	void	*collect;
	void	*exit;
	void	*open;
	void	*wall;
	void	*ground;
}			t_solong;

/*  Error Checks */
int		check_ber(char **argv);
int		check_first_line(t_solong *game);
int		check_last_line(t_solong *game);
int		check_first_index(t_solong *game);
int		check_last_index(t_solong *game);
int		check_p_c_e(t_solong *game);
int		check_p_c_e_1_0(t_solong *game);
int		check_rectangular(t_solong *game);
int		check_line_length(t_solong *game);
int		check_chars(t_solong *game);
void	error_check(t_solong *game, char **argv);
int		error_message(int error);
void	check_errors(t_solong *game);
int		ft_str_len(char *str);
void	ft_free(t_solong *game);

/* check valid path */
bool	find_path(t_solong *game, int **visited);
void	mark_path(t_solong *game, int row, int col, int **visited);
bool	found_path(t_solong *game);

/* map */
int		read_map(char **argv, t_solong *game);
int		count_number_lines(char **argv);
int		count_line_length(char **argv);

/* load images to window -- mlx */
void	get_xpm_to_img(t_solong *game);
void	load_image_to_map(t_solong *game, int x, int y);
int		create_map(t_solong *game);
int		create_loop(t_solong *game);

/* movements */
int		get_moves(int key, t_solong *game);
void	movements(t_solong *game, int i, int j);

/* general */
void	open_treaser(t_solong *game);
void	win_game(t_solong *game);
void	ft_free(t_solong *game);
int		exit_game(t_solong *game);

#endif