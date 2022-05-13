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

	int player;
	int collectible;
	int exit;


	int img_width;
	int img_height;

} 		t_solong;


/*  Error Checks */
int		check_ber(char *argv);
int		check_first_last_line(t_solong *game);
int		ft_str_chr(char *s, char c);

/* map */
void	ft_read_map(char **argv, t_solong *game);
int		count_number_lines(char **argv);
int		count_line_length(char **argv);


#endif
