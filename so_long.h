/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:15:40 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/25 12:29:20 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

# define BLOCK 64
# define WALL "./data/wall4.xpm"
# define FLOOR "./data/grass.xpm"
# define PLAYER "./data/farmer.xpm"
# define COLLECT "./data/playerbg.xpm"
# define EXIT "./data/exit3.xpm"
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ESC 53

typedef struct s_img
{
	void	*img;
	int		size_x;
	int		size_y;
	void	*player;
	void	*collect;
	void	*exit;
	void	*wall;
	void	*floor;

}		t_img;

typedef struct s_solong
{
	char	**map;
	int		map_width;
	int		map_height;
	void	*mlx;
	void	*mlx_window;
	int		steps;
	int		score;
	int		p;
	int		e;
	int		c;
	int		x_pos;
	int		y_pos;
	t_img	img;

}			t_solong;

/*  Error Checks */
int		check_ber(char **argv);
int		check_first_line(t_solong *game);
int		check_last_line(t_solong *game);
int		check_first_index(t_solong *game);
int		check_last_index(t_solong *game);
int		check_p_c_e(t_solong *game);
int		check_p_c_e_1_0(t_solong *game);
int		check_rectangular(t_solong *game);
int		check_line_length(t_solong *game);
int		check_chars(t_solong *game);
void	error_check(t_solong *game, char **argv);
int		error_message(int error);
void	check_errors(t_solong *game);
int		ft_str_len(char *str);
void	ft_free(t_solong *game);

/* map */
void	ft_read_map(char **argv, t_solong *game);
int		count_number_lines(char **argv);
int		count_line_length(char **argv);

/* load images to window -- mlx */
void	get_xpm_to_image(t_solong *game);
void	load_image_to_map(t_solong *game, int x, int y);
int		create_map(t_solong *game);

/* movements */
int		get_moves(int key, t_solong *game);
void	move_up_w(t_solong *game);
void	move_right_d(t_solong *game);
void	move_left_a(t_solong *game);
void	move_down_s(t_solong *game);

/* */
void	win_game(t_solong *game);
int		count(t_solong *game);
int		exit_game(t_solong *game);
int		create_loop(t_solong *game);

#endif
