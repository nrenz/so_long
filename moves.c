/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:15:43 by nrenz             #+#    #+#             */
/*   Updated: 2022/10/25 10:56:54 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_treaser(t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'E')
				game->map[i][j] = 'O';
			j++;
		}
		i++;
	}
	create_loop(game);
}

void	win_game(t_solong *game)
{
	char	*stp;

	if (game->score == game->c)
	{
		stp = ft_itoa(game->steps);
		ft_putstr_fd("Game over! Your steps: ", 1);
		ft_putstr_fd(stp, 1);
		ft_putstr_fd("\n", 1);
		free(stp);
		exit_game(game);
	}
}

void	movements(t_solong *game, int i, int j)
{
	if (game->map[j][i] != '1')
	{
		game->steps++;
		if (game->map[j][i] == 'C')
			game->score++;
		if (game->score == game->c)
			open_treaser(game);
		if (game->map[j][i] == 'E' || game->map[j][i] == 'O')
			win_game(game);
		if (game->last_pos == 'C')
			game->last_pos = '0';
		game->map[game->y_pos][game->x_pos] = game->last_pos;
		game->last_pos = game->map[j][i];
		game->map[j][i] = 'P';
		game->y_pos = j;
		game->x_pos = i;
		create_loop(game);
	}
}

int	get_moves(int key, t_solong *game)
{
	if (key == DOWN)
		movements(game, game->x_pos, game->y_pos + 1);
	else if (key == UP)
		movements(game, game->x_pos, game->y_pos - 1);
	else if (key == RIGHT)
		movements(game, game->x_pos + 1, game->y_pos);
	else if (key == LEFT)
		movements(game, game->x_pos - 1, game->y_pos);
	else if (key == ESC)
		exit_game(game);
	return (0);
}
