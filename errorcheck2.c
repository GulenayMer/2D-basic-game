/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:34:56 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/20 13:09:27 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* check if at least one p, c and e exist */
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

int	check_chars(t_solong *game)
{
	check_p_c_e(game);
	if (game->p == 0 || game->c == 0 || game->e == 0)
		return (1);
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
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

/* check if the all lines has the same length */
int	check_line_length(t_solong *game, char **argv)
{
	int	length;
	int	length_next;
	int	j;

	length = ft_strlen(argv[0]);
	j = 1;
	while (j < game->map_height)
	{
		length_next = ft_strlen(argv[j]);
		if (length != length_next)
			return (1);
		j++;
	}
	return (0);
}

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
		return (1);
	return (0);
}
