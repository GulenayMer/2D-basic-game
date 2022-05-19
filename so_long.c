/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:08:56 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/19 22:44:54 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*int	count(t_solong *game)
{
	game->c = 0;
	game->p = 0;
	game->e = 0;
	game->score = 0;
	check_p_c_e(game);
	return (0);
}*/

void	win_game(t_solong *game)
{
	if (game->score == game->c)
	{
		write(1, "You won", 8);
	}
}

int	exit_game(t_solong *game)
{	
	mlx_destroy_window(game->mlx, game->mlx_window);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_solong	game;

	if (argc < 2)
		return (1);
	ft_memset(&game, 0, sizeof(t_solong));
	ft_read_map(argv, &game);
	error_check(&game);
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx, (game.map_width * BLOCK), \
										(game.map_height * BLOCK), "so_long");
	//game.steps = 0;
	//count(&game);
	get_xpm_to_image(&game);
	create_map(&game);
	mlx_key_hook(game.mlx_window, &get_moves, &game);
	mlx_hook(game.mlx_window, 17, (1 << 17), &exit_game, &game);
	//mlx_loop_hook(game.mlx, &, &game);
	mlx_loop(game.mlx);
	return (0);
}
