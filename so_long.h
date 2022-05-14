#ifndef SO_LONG_H
#define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

#include <stdio.h>

typedef struct s_solong
{
	char	**map;

	int img_width;
	int img_height;

	int player;
	int collectible;
	int exit;

} 		t_solong;


/*  Error Checks */
int		check_ber(char *argv);
int		check_first_line(t_solong *game);
int		check_last_line(t_solong *game);
int		check_first_index(t_solong *game);
int		check_last_index(t_solong *game);
int		check_p_c_e(t_solong *game);
int		check_p_c_e_1_0(t_solong *game);
int		error_check(t_solong *game);

/* map */
void	ft_read_map(char **argv, t_solong *game);
int		count_number_lines(char **argv);
int		count_line_length(char **argv);


#endif
