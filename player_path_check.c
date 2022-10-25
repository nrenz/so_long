/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_path_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:41:50 by nrenz             #+#    #+#             */
/*   Updated: 2022/10/10 17:22:20 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
	compare virtual colacts and gates
	with the real amont of them 
*/
bool	find_path(t_solong *game, int **visited)
{
	int	gates;
	int	col_items;
	int	row;
	int	col;

	row = -1;
	gates = 0;
	col_items = 0;
	while (game->map[++row])
	{
		col = -1;
		while (game->map[row][++col])
		{
			if (game->map[row][col] == 'E')
				if (visited[row][col])
					gates++;
			if (game->map[row][col] == 'C')
				if (visited[row][col])
					col_items++;
		}
		if ((col_items + gates) == (game->e + game->c))
			return (true);
	}
	return (false);
}

/* 	
	line46: don't retrun, because we only mark which fields is possible to visited
	line47: if not a wall and not visited 
	line51: if it possible to visit mark 1 
*/
void	mark_path(t_solong *game, int row, int col, int **visited)
{
	if ((row < 0 || row >= game->map_height) && \
				(col < 0 || col >= game->map_height))
		return ;
	if (game->map[row][col] != '1' && !visited[row][col])
	{
		visited[row][col] = 1;
		mark_path(game, row, col + 1, visited);
		mark_path(game, row, col - 1, visited);
		mark_path(game, row - 1, col, visited);
		mark_path(game, row + 1, col, visited);
	}
}

/* 
	is path valid
	line78: memory for visited fields in the visual map 
*/
bool	found_path(t_solong *game)
{
	int		**visited;
	int		count;
	bool	valid;

	count = 0;
	valid = true;
	visited = (int **)ft_calloc(10, sizeof(int *));
	while (count < game->map_height)
	{
		visited[count] = (int *)ft_calloc(game->map_width, sizeof(int));
		count ++;
	}
	mark_path(game, game->y_pos, game->x_pos, visited);
	valid = find_path(game, visited);
	while (--count >= 0)
		free(visited[count]);
	free(visited);
	return (valid);
}
