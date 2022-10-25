/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:56:18 by nrenz             #+#    #+#             */
/*   Updated: 2022/10/13 15:24:26 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
line 24: open first line
line 30: free memory for the first line
line 33: how many lines exists 
*/

int	count_number_lines(char **argv)
{
	char	*line;
	int		map_fd;
	int		line_count;

	map_fd = open(argv[1], O_RDONLY);
	line = get_next_line(map_fd);
	line_count = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(map_fd);
		line_count++;
	}
	close(map_fd);
	return (line_count);
}

int	count_line_length(char **argv)
{
	char	*line;
	int		map_fd;
	int		line_length;

	map_fd = open(argv[1], O_RDONLY);
	line = get_next_line(map_fd);
	line_length = ft_strlen(line);
	free(line);
	close(map_fd);
	return (line_length);
}

int	read_map(char **argv, t_solong *game)
{
	char	*line;
	int		map_fd;
	int		line_count;

	map_fd = open(argv[1], O_RDONLY);
	if (map_fd < 0)
	{
		write(1, "Error:\nThere is no such a file\n", 32);
		return (0);
	}
	game->map_height = count_number_lines(argv);
	game->map = (char **)calloc(game->map_height + 1, sizeof(char *));
	if (!game->map)
		return (0);
	game->map_width = count_line_length(argv) - 1;
	line_count = 0;
	line = get_next_line(map_fd);
	while (line != NULL)
	{
		game->map[line_count] = line;
		line = get_next_line(map_fd);
		line_count++;
	}
	close(map_fd);
	return (1);
}
