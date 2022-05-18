/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:45:31 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/18 18:53:11 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_solong *game)
{
	
}


int	get_moves(t_solong *game, int key)
{
	if (key == DOWN)
		move_down(game);
	else if (key == UP)
		move_up(game);
	else if (key == RIGHT)
		move_right(game);
	else if (key == LEFT)
		move_left(game);
	else if (key == ESC)
		quit_game(game);
	return (0);
}
