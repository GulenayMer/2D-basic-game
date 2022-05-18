/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:31:57 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/18 15:25:08 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* check if the map has ber extension */
int	check_ber(char *argv)
{
	int	argv_first_length;
	int	index;

	argv_first_length = ft_strlen(argv);
	index = argv_first_length - 1;
	if (argv[index] == 'r' && argv[index - 1] == 'e' && argv[index - 2] == 'b'
		&& argv[index - 3] == '.')
		return (0);
	else
		return (1);
}

/* check if the first line is filled with 1s */
int	check_first_line(t_solong *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < game->map_width)
	{
		if (game->map[j][i] != '1')
			return (1);
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
			return (1);
		i++;
	}
	return (0);
}

/* check if the first indexes of the lines are filled with 1s */
int	check_first_index(t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->map_height)
	{
		if (game->map[j][i] != '1')
			return (1);
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
			return (1);
		j++;
	}
	return (0);
}
