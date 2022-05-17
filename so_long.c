/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:08:56 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/17 17:46:03 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The MAP  
	-- 's extension must be .BER  -- CHECKED
	-- must contain at least 1 exit, 1 collectible, 1 starting postion
	-- must be rectangular
	-- must be surrounded by walls
	0 -- empty space
	1 -- wall
	C -- collectible
	E -- exit
	P -- players starting position
*/

/* GRAPHIC MANAGEMENT
	-- the program must display the img in a window
	-- the window management should be reponsive?
	-- ESC must close the window & quit the program
	-- use of images of MLX
 */

 /* GAME
	-- collect & escape by chosing the shortest poss. route
	-- KEYS: W, A, S, D to move the main character
	-- The player should be move to up, down, left and right.
	-- The player should not be able to move into walls.
	-- At every move, the current num. of movements must be displayed in 
	the shell
	-- 2D view-- top dow or profile 
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
	game.mlx_window = mlx_new_window(game.mlx, (game.img_width * 100), \
										(game.img_height * 100), "so_long");
	create_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
