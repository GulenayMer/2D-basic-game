/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:08:56 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/25 13:42:29 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count(t_solong *game)
{
	game->c = 0;
	game->p = 0;
	game->e = 0;
	game->score = 0;
	check_p_c_e(game);
	return (0);
}

void	win_game(t_solong *game)
{
	char	*stp;

	stp = ft_itoa(game->steps);
	if (game->score == game->c)
	{
		game->steps++;
		ft_putstr_fd("Game over. Steps taken: \n", 1);
		ft_putstr_fd(stp, 1);
		ft_putstr_fd("\n", 1);
		ft_free(game);
		free(stp);
		exit(0);
	}
}

void	ft_free(t_solong *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
}

int	exit_game(t_solong *game)
{	
	mlx_destroy_window(game->mlx, game->mlx_window);
	ft_free(game);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_solong	game;

	if (argc < 2)
		return (1);
	check_ber(argv);
	ft_read_map(argv, &game);
	check_errors(&game);
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx, (game.map_width * BLOCK), \
										(game.map_height * BLOCK), "so_long");
	count(&game);
	game.steps = 0;
	get_xpm_to_image(&game);
	create_map(&game);
	mlx_key_hook(game.mlx_window, get_moves, &game);
	mlx_hook(game.mlx_window, 17, 0L, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
