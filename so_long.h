/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:33:05 by nrenz             #+#    #+#             */
/*   Updated: 2022/07/11 12:35:27 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include "mlx/mlx.h"

typedef struct s_game_map
{
	int		map_height;
	int		map_weight;
	int		player_position_x;
	int		player_position_y;
	int		game_score; // current score if C than = 0
	int		max_score; // all collectable items
	char	**map_data;
	int		game_over;
	int		steps;
	void	*end_img;
	void	*wall;
	void	*exit;
	void	*player;
	void	*floor;
	void	*items;
	void	*enemy;
	void	*enemypos;
}	t_game_map;

typedef struct s_render_v
{
	void	*mlx;
	void	*win;
}	t_render_v;