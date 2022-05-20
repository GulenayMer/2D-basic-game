/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:45:31 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/20 13:02:45 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up_w(t_solong *game)
{
	int	i;
	int	j;

	i = game->x_pos;
	j = game->y_pos;
	if (game->map[j - 1][i] != '1')
	{
		if (game->map[j - 1][i] == 'C')
			game->score++;
		else if (game->map[j - 1][i] == 'E')
			win_game(game);
		game->map[j][i] = '0';
		game->map[j - 1][i] = 'P';
		game->y_pos--;
		game->steps++;
		create_loop(game);
	}
}

void	move_down_s(t_solong *game)
{
	int	i;
	int	j;

	i = game->x_pos;
	j = game->y_pos;
	printf("Hello\n");
	if (game->map[j + 1][i] != '1')
	{
		if (game->map[j + 1][i] == 'C' || game->map[j + 1][i] == 'E')
			game->score++;
		else if (game->map[j + 1][i] == 'E')
			win_game(game);
		game->map[j + 1][i] = 'P';
		game->map[j][i] = '0';
		game->y_pos++;
		game->steps++;
		create_loop(game);
	}
}

void	move_left_a(t_solong *game)
{	
	int	i;
	int	j;

	i = game->x_pos;
	j = game->y_pos;
	if (game->map[j][i - 1] != '1')
	{
		if (game->map[j][i - 1] == 'C')
			game->score++;
		else if (game->map[j][i - 1] == 'E')
			win_game(game);
		game->map[j][i] = '0';
		game->map[j][i - 1] = 'P';
		game->x_pos--;
		game->steps++;
		create_loop(game);
	}
}

void	move_right_d(t_solong *game)
{	
	int	i;
	int	j;

	i = game->x_pos;
	j = game->y_pos;
	if (game->map[j][i + 1] != '1')
	{
		if (game->map[j][i + 1] == 'C')
			game->score++;
		else if (game->map[j][i + 1] == 'E')
			win_game(game);
		game->map[j][i] = '0';
		game->map[j][i + 1] = 'P';
		game->x_pos++;
		game->steps++;
		create_loop(game);
	}
}

int	get_moves(int key, t_solong *game)
{
	printf("in get_moves\n");
	if (key == DOWN)
		move_down_s(game);
	else if (key == UP)
		move_up_w(game);
	else if (key == RIGHT)
		move_right_d(game);
	else if (key == LEFT)
		move_left_a(game);
	else if (key == ESC)
		exit_game(game);
	return (0);
}
