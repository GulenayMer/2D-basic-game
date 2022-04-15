
/* The MAP  
	-- 's extension must be .BER
	-- must contain at least 1 exit, 1 collectible, 1 starting postion
	-- must be rectangular
	-- must be surrounded by walls
	0 -- empty space
	1 -- wall
	C -- collectible
	E -- exit
	P -- players starting position
*/

/* GRAPHIC MANAGEMENT
	-- the program must display the img in a window
	-- the window management should be reponsive?
	-- ESC must close the window & quit the program
	-- use of images of MLX
 */

 /* GAME
	-- collect & escape by chosing the shortest poss. route
	-- KEYS: W, A, S, D to move the main character
	-- The player should be move to up, down, left and right.
	-- The player should not be able to move into walls.
	-- At every move, the current num. of movements must be displayed in 
	the shell
	-- 2D view-- top dow or profile 
 */

/* Extrn funct: open, close, read, write, malloc, free, perror, strerror, exit */



#include "so_long.h"

#include <stdlib.h>

int	main()
{
	t_program program;
	t_window  window;
	window.x_width = 800;
	window.y_height = 600;

	int *texture_h = malloc(sizeof(int));
	int *texture_w = malloc(sizeof(int));

	/*  return error :
		1) extension !(ber), 
		2) !(pce10)	
		3) !(surrounded by walls)

		("Error\n")
	*/

	/* if not error: */
	program.mlx = mlx_init();
	program.mlx_window = mlx_new_window(program.mlx, window.x_width, window.y_height, "so_long");

	for (int i = 0; i < window.x_width; i++) 
	{
		mlx_pixel_put(program.mlx, program.mlx_window, i, window.y_height / 5, 0xFF5733);
	}

	program.img = mlx_xpm_file_to_image(program.mlx, "./download.xpm", texture_w, texture_h);
	mlx_put_image_to_window(program.mlx, program.mlx_window, program.img, *texture_w, *texture_w);

	mlx_loop(program.mlx);
}
