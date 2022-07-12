/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:49:15 by nrenz             #+#    #+#             */
/*   Updated: 2022/07/11 18:47:51 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_map	map_data;
	int			error;
	
	error = 0;
	t_game_map = (t_game_map){}; // Null all variablies in the struct
	if (argc > 2 || argc == 1)
		return (1);
	fd = open(argv[1], O_RONLY);
	if (fd != -1)
	{
		error = parse_func(fd, &map_data);
		if (error != 0)
			if (error == -1){}
				printf("Width of the maps is not the same")
				return(-1);
			}
	}
	else
		return (1);
	mlx_drawing(&map_data);
}

int parse_func(int fd, t_game_map *map, char *argv)
{
	char	*result;
	int		i;
	int		y;
	
	i = 0;
	y = 0;
	while (result != NULL)
	{	
		result = get_next_line(fd);
		map->map_height++;
		if (i == 0)
		{	
			while(result[y])
				y++;
			map->map_weight = y;
		}
		else
		{
			while(result[y])
				y++;
			if (map->map_weight != y)
				return (-1);
		}
		free(result);
		y = 0;
		i++;
	}
	open(argv)
	while
}

argc = 2 
argv** =

[ -> . [0]
	[
		/so_long_test\0	
	]
  -> m [1]
	[
		->ap.ber\0
	]
]