/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:57:15 by nrenz             #+#    #+#             */
/*   Updated: 2022/10/13 15:57:37 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_message(int error)
{
	if (error == 1)
		write(1, "Error:\nCheck the map format\n", 28);
	if (error == 2)
		write(1, "Error:\nNot only p, c, e, 1, 0\n", 30);
	if (error == 3)
		write(1, "Error:\nInvalid map structure\n", 29);
	if (error == 4)
		write(1, "Error:\nInvalid lines\n", 21);
	if (error == 5)
		write(1, "Error:\nAt least one p, c, e needed\n", 35);
	if (error == 6)
		write(1, "Error:\nPath is not valid\n", 25);
	exit(1);
}

void	check_errors(t_solong *game)
{
	check_first_index(game);
	check_last_index(game);
	check_first_line(game);
	check_last_line(game);
	check_chars(game);
	check_p_c_e_1_0(game);
	check_line_length(game);
}
