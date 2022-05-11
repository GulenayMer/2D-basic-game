#ifndef SO_LONG_H
#define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_vars
{
	int		collectible;
	int		player;
	int		exit;

}			t_vars;

/* vector variables for the window & image */
typedef struct s_window
{
	int		x_width;
	int		y_height;
}			t_window;

/* image */
typedef struct s_image
{
	t_window	size;

}			t_image;

/*  mlx program */
typedef struct s_program
{
	void		*mlx;
	t_image		*img;
	t_window	*mlx_window;
}			t_program;



#endif
