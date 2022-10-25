/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:54:00 by nrenz             #+#    #+#             */
/*   Updated: 2022/10/13 14:46:59 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_p_c_e(t_solong *game)
{
	int	i;
	int	j;

	j = 1;
	while (j < game->map_height - 1)
	{
		i = 0;
		while (i < game->map_width)
		{
			if (game->map[j][i] == 'P')
			{
					game->p++;
					game->x_pos = i;
					game->y_pos = j;
			}
			if (game->map[j][i] == 'C')
				game->c++;
			if (game->map[j][i] == 'E')
				game->e++;
			i++;
		}
		j++;
	}
	return (0);
}

/* check if at least one p, c and e exist */
int	check_chars(t_solong *game)
{
	check_p_c_e(game);
	if (game->p != 1 || game->c == 0 || game->e == 0)
		return (error_message(5));
	return (0);
}

/* check if only p, c, e, 1 and 0 exist */
int	check_p_c_e_1_0(t_solong *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			if (game->map[j][i] != 'P' && game->map[j][i] != 'E' \
			&& game->map[j][i] != 'C' && game->map[j][i] != '1' \
			&& game->map[j][i] != '0')
				return (error_message(2));
			i++;
		}
		j++;
	}
	return (0);
}

/* check if the all lines has the same length */
int	ft_str_len(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0' && str[count] != '\n')
		count++;
	return (count);
}

int	check_line_length(t_solong *game)
{
	int	length;
	int	length_next;
	int	j;

	length = ft_str_len(game->map[0]);
	j = 1;
	while (j < game->map_height)
	{
		length_next = ft_str_len(game->map[j]);
		if (length_next != length)
			return (error_message(4));
		j++;
	}
	return (0);
}
