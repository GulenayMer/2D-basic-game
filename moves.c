/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:45:31 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/19 17:05:15 by mgulenay         ###   ########.fr       */
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
		if (game->map[j - 1][i] == 'E')
			win_game(game);
	}
	else
	{
		game->map[j][i] = '0';
		game->map[j - 1][i] = 'P';
		j--;
		game->steps++;
	}
}

void	move_down_a(t_solong *game)
{
	int	i;
	int	j;

	i = game->x_pos;
	j = game->y_pos;
	if (game->map[j + 1][i] != '1')
	{
		if (game->map[j + 1][i] == 'C')
			game->score++;
		if (game->map[j + 1][i] == 'E')
			win_game(game);
	}
	else
	{
		game->map[j][i] = '0';
		game->map[j + 1][i] = 'P';
		j++;
		game->steps++;
	}
}

void	move_left_s(t_solong *game)
{	
	int	i;
	int	j;

	i = game->x_pos;
	j = game->y_pos;
	if (game->map[j][i - 1] != '1')
	{
		if (game->map[j][i - 1] == 'C')
			game->score++;
		if (game->map[j][i - 1] == 'E')
			win_game(game);
	}
	else
	{
		game->map[j][i] = '0';
		game->map[j][i - 1] = 'P';
		i--;
		game->steps++;
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
		if (game->map[j][i + 1] == 'E')
			win_game(game);
	}
	else
	{
		game->map[j][i] = '0';
		game->map[j][i + 1] = 'P';
		i++;
		game->steps++;
	}
}

int	get_moves(t_solong *game, int key)
{
	if (key == DOWN)
		move_down_a(game);
	else if (key == UP)
		move_up_w(game);
	else if (key == RIGHT)
		move_right_d(game);
	else if (key == LEFT)
		move_left_s(game);
	/*else if (key == ESC)
		quit_game(game);*/
	return (0);
}
