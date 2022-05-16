/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:17:41 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/16 20:17:13 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* getting xpm files to images via mlx func. 
void *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
			int *width, int *height);
*/
void	get_xpm_to_image(t_solong *game, char c)
{
	if (c == '0')
		game->empty = mlx_xpm_file_to_image(game->mlx, "./data/grass.xpm", \
										game->img.size_x, game->img.size_y);
	else if (c == '1')
		game->wall = mlx_xpm_file_to_image(game->mlx, "./data/walls.xpm", \
										game->img.size_x, game->img.size_y);
	else if (c == 'P')
		game->player = mlx_xpm_file_to_image(game->mlx, "./data/farmer.xpm", \
											game->img.size_x, game->img.size_y);
	else if (c == 'C')
		game->collectible = mlx_xpm_file_to_image(game->mlx, \
					"./data/apple.xpm", game->img.size_x, game->img.size_y);
	else if (c == 'E')
		game->exit = mlx_xpm_file_to_image(game->mlx, "./data/exit.xpm", \
							game->size_x, game->size_y);
}

/* int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, 
								void *img_ptr, int x, int y) */
void	put_image_to_window(t_solong *game, char c)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
							game->empty, x * 100, y * 100);
	else if (c == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
							game->wall, x * 100, y * 100);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
							game->player, x * 100, y * 100);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
							game->collectible, x * 100, y * 100);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
							game->exit, x * 100, y * 100);
}

/* loading images to map via mlx func. */
void	load_image_to_map(t_solong *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->img_height)
	{
		i = 0;
		while (i < game->img_width)
		{
			if (game->map[j][i] == '1')
			{
				get_xpm_to_image(&game, '1');
				put_image_to_window(&game, '1');
			}
			else if (game->map[j][i] == '0')
			{
				get_xpm_to_image(&game, '0');
				put_image_to_window(&game, '0');
			}
			i++;
		}
		j++;
		i = 0;
	}
}

void	load_image_to_map2(t_solong *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->img_height)
	{
		i = 0;
		while (i < game->img_width)
		{
			if (game->map[j][i] == 'P')
			{
				get_xpm_to_image(&game, 'P');
				put_image_to_window(&game, 'P');
			}
			else if (game->map[j][i] == 'C')
			{
				get_xpm_to_image(&game, 'C');
				put_image_to_window(&game, 'C');
			}
			else if (game->map[j][i] == 'E')
			{
				get_xpm_to_image(&game, 'E');
				put_image_to_window(&game, 'E');
			}
			i++;
		}
		j++;
		i = 0;
	}
}
