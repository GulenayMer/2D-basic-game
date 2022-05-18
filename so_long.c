/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:08:56 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/18 18:55:45 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* GRAPHIC MANAGEMENT
	-- ESC must close the window & quit the program
 */
 /* GAME
	-- collect & escape by chosing the shortest poss. route
	-- KEYS: W, A, S, D to move the main character
	-- The player should be move to up, down, left and right.
	-- The player should not be able to move into walls.
	-- At every move, the current num. of movements must be displayed in 
	the shell
 */
#include "so_long.h"

int	error_check(t_solong *game)
{
	if (check_first_line(game) || check_last_line(game) \
	|| check_first_index(game) || check_last_index(game) \
	|| check_p_c_e(game) || check_p_c_e_1_0(game))
	{
		write(1, "Error with the map\n", 20);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_solong	game;

	if (argc < 2)
		return (1);
	ft_read_map(argv, &game);
	error_check(&game);
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx, (game.map_width * BLOCK), \
										(game.map_height * BLOCK), "so_long");
	get_image_to_map(&game);
	create_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
