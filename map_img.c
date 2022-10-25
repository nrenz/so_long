/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:25:26 by nrenz             #+#    #+#             */
/*   Updated: 2022/10/13 14:38:04 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* xpm files as pixels */
void	get_xpm_to_img(t_solong *game)
{
	int	tmp;

	tmp = 0;
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &tmp, &tmp);
	game->ground = mlx_xpm_file_to_image(game->mlx, GROUND, &tmp, &tmp);
	game->player = mlx_xpm_file_to_image(game->mlx, PLAYER, &tmp, &tmp);
	game->collect = mlx_xpm_file_to_image(game->mlx, COLLECT, &tmp, &tmp);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &tmp, &tmp);
	game->open = mlx_xpm_file_to_image(game->mlx, OPEN, &tmp, &tmp);
}

/* images to the map */
void	load_image_to_map(t_solong *game, int i, int j)
{
	int	x;
	int	y;

	x = i * BLOCK;
	y = j * BLOCK;
	if (game->map[j][i] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
								game->wall, x, y);
	else if (game->map[j][i] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
								game->ground, x, y);
	else if (game->map[j][i] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
								game->player, x, y);
	else if (game->map[j][i] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
								game->collect, x, y);
	else if (game->map[j][i] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->exit, x, y);
	else if (game->map[j][i] == 'O')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->open, x, y);
}

int	create_map(t_solong *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			load_image_to_map(game, i, j);
			i++;
		}
		j++;
	}
	return (0);
}

/* 	mlx_string_put_function 
	draws a defined pixel in the window 
	using the (x, y) coordinates
	and the specified color
*/
int	create_loop(t_solong *game)
{
	char	*steps;

	create_map(game);
	steps = ft_itoa(game->steps);
	ft_putstr_fd("Steps: ", 1);
	ft_putstr_fd(steps, 1);
	ft_putstr_fd("\n", 1);
	free(steps);
	return (0);
}
