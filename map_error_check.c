/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:09:41 by nrenz             #+#    #+#             */
/*   Updated: 2022/10/07 18:16:51 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* check if the map has ber extension */
int	check_ber(char **argv)
{
	int	argv_first_length;
	int	index;

	argv_first_length = ft_strlen(argv[1]);
	index = argv_first_length - 1;
	if (argv[1][index] == 'r' && argv[1][index - 1] == 'e' \
		&& argv[1][index - 2] == 'b'
		&& argv[1][index - 3] == '.')
		return (0);
	else
		return (error_message(1));
}

/* check if 1st row filled 1s */
int	check_first_line(t_solong *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1')
			return (error_message(3));
		i++;
	}
	return (0);
}

/* check if the last line is filled with 1s */
int	check_last_line(t_solong *game)
{
	int	i;
	int	j;

	j = game->map_height - 1;
	i = 0;
	while (i < game->map_width)
	{
		if (game->map[j][i] != '1')
			return (error_message(3));
		i++;
	}
	return (0);
}

/* check if the first indexes of the lines are filled with 1s */
int	check_first_index(t_solong *game)
{
	int	j;

	j = 0;
	while (j < game->map_height)
	{
		if (game->map[j][0] != '1')
			return (error_message(3));
		j++;
	}
	return (0);
}

/* check if the last indexes of the lines are filled with 1s */
int	check_last_index(t_solong *game)
{
	int	i;
	int	j;

	i = game->map_width - 1;
	j = 0;
	while (j < game->map_height)
	{
		if (game->map[j][i] != '1')
			return (error_message(3));
		j++;
	}
	return (0);
}
