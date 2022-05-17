/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:34:56 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/17 17:03:14 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* check if at least one p, c and e exist */
int	check_p_c_e(t_solong *game)
{
	int	i;
	int	j;

	j = 1;
	while (j < game->img_height - 1)
	{
		i = 0;
		while (i < game->img_width)
		{
			if (game->map[j][i] == 'P')
				game->player++;
			if (game->map[j][i] == 'C')
				game->collectible++;
			if (game->map[j][i] == 'E')
				game->exit++;
			i++;
		}
		j++;
	}
	if (game->player == 0 || game->collectible == 0 || game->exit == 0)
		return (1);
	return (0);
}

/* check if only p, c, e, 1 and 0 exist */
int	check_p_c_e_1_0(t_solong *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->img_height)
	{
		i = 0;
		while (i < game->img_width)
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

int	strlen_helper(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

/* check if the all lines has the same length */
int	check_line_length(t_solong *game, char **argv)
{
	int	length;
	int	length_next;
	int	j;

	length = ft_strlen(argv[0]);
	//printf("%d\n", length);
	//length_next = strlen_helper(*(game->map));
	//printf("%d\n", length);
	j = 1;
	while (j < game->img_height)
	{
		length_next = ft_strlen(argv[j]);
		if (length != length_next)
		{
			printf("lines are not equal\n");
			return (1);
		}
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
	while (j < game->img_height)
		j++;
	i = 0;
	while (i < game->img_width)
		i++;
	j--;
	i--;
	if (j == i)
	{
		printf("not a retangular\n");
		return (1);
	}
	return (0);
}
