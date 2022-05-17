/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:17:41 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/18 00:05:37 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* loading xpm files as pixels */
void	get_image_to_map(t_solong *game, char c)
{
	if (c == '0')
		game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, \
										&game->img.size_x, &game->img.size_y);
	else if (c == '1')
		game->wall = mlx_xpm_file_to_image(game->mlx, WALL, \
										&game->img.size_x, &game->img.size_y);
	else if (c == 'P')
		game->player = mlx_xpm_file_to_image(game->mlx, PLAYER, \
										&game->img.size_x, &game->img.size_y);
	else if (c == 'C')
		game->collect = mlx_xpm_file_to_image(game->mlx, COLLECT, \
						&game->img.size_x, &game->img.size_y);
	else if (c == 'E')
		game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, \
							&game->img.size_x, &game->img.size_y);
}

void	load_image_to_map(t_solong *game, char c, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->img_height)
	{
		i = 0;
		while (i < game->img_width)
		{
			c = game->map[j][i];
			if (c == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_window, \
						game->wall, x, y);
			else if (c == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_window, \
						game->floor, x, y);
			else if (c == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_window, \
						game->player, x, y);
			else if (c == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_window, \
						game->collect, x, y);
			else if (c == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_window, \
						game->exit, x, y);
			i++;
		}
		j++;
		i = 0;
	}
}

void	create_map(t_solong *game)
{
	int	i;
	int	j;

	game->img.horizontal = 0;
	game->img.vertical = 0;
	j = 0;
	while (j < game->img_height)
	{
		while (i < game->img_width)
		{
			load_image_to_map(game, game->map[j][i], \
						game->img.horizontal, game->img.vertical);
			i++;
			game->img.horizontal += 64;
		}
		game->img.horizontal = 0;
		game->img.vertical += 64;
		j++;
		i = 0;
	}
}

