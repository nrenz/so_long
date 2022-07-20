/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:49:15 by nrenz             #+#    #+#             */
/*   Updated: 2022/07/13 15:10:09 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_memory(t_game_map *game_map)
{
	game_map = ft_calloc(1, sizeof(t_game_map));
	game_map->map = ft_calloc(1, sizeof(char **));
}

int	main(int argc, char **argv)
{
	t_game_map	*game_map;
	int			i;
	int			fd;
	char		*map_line;
	
	t_game_map = (t_game_map){}; // Null all variablies in the struct
	if (argc > 2 || argc == 1)
		return (1);
	
	
	i = 0;
	ft_check_ber_format(argv[1]);
	fd = open(argv[1], O_RDONLY);
	map_line = get_next_line(fd);
	while (map_line != NULL)
	{
		map_data->map[i++] = ft_strdup(map_line);
		free(map_line);
		map_line = get_next_line(fd);
	}
	