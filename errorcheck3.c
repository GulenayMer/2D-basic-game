/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:22:16 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/24 22:42:36 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* check if the map is rectangular */
int	check_rectangular(t_solong *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map_height)
		j++;
	i = 0;
	while (i < game->map_width)
		i++;
	j--;
	i--;
	if (j == i)
		return (error_message(6));
	return (0);
}

int	error_message(int error)
{
	if (error == 1)
		write(1, "Check the map extension\n", 25);
	if (error == 2)
		write(1, "not only p, c, e, 1, 0\n", 24);
	if (error == 3)
		write(1, "not surrounded with walls\n", 27);
	if (error == 4)
		write(1, "Error with the lines\n", 22);
	if (error == 5)
		write(1, "at least one p, c, e needed\n", 29);
	if (error == 6)
		write(1, "should be rectangular\n", 23);
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
	check_rectangular(game);
}
