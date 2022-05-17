/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:17:41 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/17 18:08:27 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* loading xpm files as pixels */
void	get_image_to_map(t_solong *game, char c, int x, int y)
{
	if (c == '0')
	{
		game->empty = mlx_xpm_file_to_image(game->mlx, "./data/grass.xpm", \
										&game->img.size_x, &game->img.size_y);
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->empty, x, y);
	}
	else if (c == '1')
	{
		game->wall= mlx_xpm_file_to_image(game->mlx, "./data/wall.xpm", \
										&game->img.size_x, &game->img.size_y);
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->wall, x, y);
	}
	else if (c == 'P')
	{
		game->player = mlx_xpm_file_to_image(game->mlx, "./data/farmer.xpm", \
										&game->img.size_x, &game->img.size_y);
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->player, x, y);
	}
	else if (c == 'C')
	{
		game->collectible = mlx_xpm_file_to_image(game->mlx, \
					"./data/apple.xpm", &game->img.size_x, &game->img.size_y);
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->collectible, x, y);
	}
	else if (c == 'E')
	{
		game->exit = mlx_xpm_file_to_image(game->mlx, "./data/exit.xpm", \
							&game->img.size_x, &game->img.size_y);
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->exit, x, y);
	}
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
				get_image_to_map(game, c, x , y);
			else if (c == '0')
				get_image_to_map(game, c, x , y);
			else if (c == 'P')
				get_image_to_map(game, c, x , y);
			else if (c == 'C')
				get_image_to_map(game, c, x , y);
			else if (c == 'E')
				get_image_to_map(game, c, x, y);
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

	game->img.horizontal_point = 0;
	game->img.vertical_point = 0;
	j = 0;
	while (j < game->img_height)
	{
		while (i < game->img_width)
		{
			load_image_to_map(game, game->map[j][i], game->img.horizontal_point, game->img.vertical_point);
			i++;
			game->img.horizontal_point += 64;
		}
		//game->img.horizontal_point = 0;
		game->img.vertical_point += 64;
		j++;
		i = 0;
	}
}
