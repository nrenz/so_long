/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_error_checker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:09:41 by nrenz             #+#    #+#             */
/*   Updated: 2022/07/13 17:23:35 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ber_format(char *path)
{
	char	*res;

	res = ft_strrchr(path, '.');
	if (ft_strlen(res) != 4)
		return (1);
	if (ft_strncmp(res, ".ber", 4))
		return (0);
	return (1);
}

int	ft_check_map_wall(t_game_map *game_map)
{
	int	i;

	i = 0;
	while (game_map->map[0][i] != '\0')
	{
		if (game_map->map[0][i] != 1) // first line of the map with "1"
			return (1);
		i++;
	}
	game_map->width = i; // the width of the map
	i = 0;
	while (game_map->map[i])
	{
		i++; // the height of the map
	}
	game_map->height = i;
	i = 0;
	while (game_map->map[i][0] != '\0')
	{
		if (game_map->map[i][0] != 1) // last line of the map with "1"
			return (1);
		i++;
	}
}

int	ft_check_map_wall2(t_game_map *game_map)
{
	
}

int	ft_map_allowed_sign(t_game_map *game_map)
{
	if (game_map->map[i] != 0 || game_map->map[i] != 1
		|| game_map->map[i] != 'P' || game_map->map[i] != 'C'
		|| game_map->map[i] != 'E')
		return (1);
}
