/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:15:40 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/16 20:19:02 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct s_img
{
	void	*img;
	int		size_x;
	int		size_y;
	int		x;
	int		y;

}		t_img;

typedef struct s_solong
{
	char	**map;
	int		img_width;
	int		img_height;
	int		player;
	int		collectible;
	int		exit;
	int		wall;
	int		empty;
	void	*mlx;
	void	*mlx_window;
	t_img	img;

}			t_solong;


/*  Error Checks */
int		check_ber(char *argv);
int		check_first_line(t_solong *game);
int		check_last_line(t_solong *game);
int		check_first_index(t_solong *game);
int		check_last_index(t_solong *game);
int		check_p_c_e(t_solong *game);
int		check_p_c_e_1_0(t_solong *game);
int		error_check(t_solong *game);
int		check_rectangular(t_solong *game);
int		check_line_length(t_solong *game, char **argv);

/* map */
void	ft_read_map(char **argv, t_solong *game);
int		count_number_lines(char **argv);
int		count_line_length(char **argv);

/* load images to window -- mlx */
void	get_xpm_to_image(t_solong *game, char c);
void	load_image_to_map(t_solong *game);
void	load_image_to_map2(t_solong *game);


#endif
