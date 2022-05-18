/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:17:41 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/18 17:31:28 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* xpm files as pixels */
void	get_xpm_to_image(t_solong *game)
{
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, \
									&game->img.size_x, &game->img.size_y);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, \
									&game->img.size_x, &game->img.size_y);
	game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER, \
									&game->img.size_x, &game->img.size_y);
	game->img.collect = mlx_xpm_file_to_image(game->mlx, COLLECT, \
					&game->img.size_x, &game->img.size_y);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT, \
						&game->img.size_x, &game->img.size_y);

}

/* images to the map */
void	load_image_to_map(t_solong *game, int i, int j)
{
	size_t	x;
	size_t	y;

	x = i * BLOCK;
	y = j * BLOCK;
	if (game->map[j][i] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
				game->img.wall, x, y);
	else if (game->map[j][i] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
				game->img.floor, x, y);
	else if (game->map[j][i] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
				game->img.player, x, y);
	else if (game->map[j][i] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
				game->img.collect, x, y);
	// else if (game->map[j][i] == 'E')
	// 	mlx_put_image_to_window(game->mlx, game->mlx_window, \
	// 			game->img.exit, x, y);
}

void	create_map(t_solong *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			load_image_to_map(game, i, j);
			i++;
		}
		j++;
	}
}
