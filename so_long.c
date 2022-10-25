/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:49:15 by nrenz             #+#    #+#             */
/*   Updated: 2022/10/13 15:26:44 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_solong *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->ground);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->open);
	mlx_destroy_window(game->mlx, game->mlx_window);
	ft_free(game);
	exit(0);
}

/* 
	free each columns we created, because it is a two pointer char
*/
void	ft_free(t_solong *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
}

/* 	initilize mlx with mlx_init()
	open window mlx_new_window
	hook into the events
	mlx_loop is an infinite loop
	it keep program running, window open, 
   	call event (code of event), 
	as MacOS doesn't support X11 mask 
	no event mask (0L)
*/
int	main(int argc, char **argv)
{
	t_solong	*game;

	if (argc < 2)
		return (1);
	check_ber(argv);
	game = (t_solong *)ft_calloc(1, sizeof(t_solong));
	if (!read_map(argv, game))
		return (free(game), 1);
	check_errors(game);
	if (!found_path(game))
	{
		ft_free(game);
		return (error_message(6));
	}
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, (game->map_width * BLOCK), \
						(game->map_height * BLOCK), "so_long");
	game->last_pos = '0';
	get_xpm_to_img(game);
	create_map(game);
	mlx_key_hook(game->mlx_window, get_moves, game);
	mlx_hook(game->mlx_window, 17, 0L, exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
