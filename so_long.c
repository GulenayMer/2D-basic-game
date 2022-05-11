
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




	/*  return error :
		1) extension !(ber), 
		2) !(pce10)	
		3) !(surrounded by walls)
		("Error\n")
	*/
// #include "so_long.h"
#include <stdio.h>
#include "libft/libft.h"
#include <fcntl.h>

typedef struct s_data
{
	t_data *map_lines;

} t_data;

/* check if the map has ber extension */
int	check_ber(char *argv)
{
	int	argv_first_length;
	int	index;

	argv_first_length = ft_strlen(argv);
	index = argv_first_length - 1;
	if (argv[index] == 'r' && argv[index - 1] == 'e' && argv[index - 2] == 'b' && argv[index - 3] == '.')
		{
			//printf("has .ber\n");
			return (0);
		}
	else
	{
		//printf("no .ber\n");
		return (1);
	}
}

/*    check map errors */





int	main(int argc, char **argv)
{
	int		mapfd;
	char	*line;
	t_data	*map_lines;
	int		count;

	if (argc < 2)
		return (1);
	mapfd = open(argv[1], O_RDONLY);
	if (!mapfd)
	{
		perror("could not read the map");
		exit (1);
	}
	check_ber(argv[1]);
	
	count = 0;
	line = get_next_line(mapfd);
	//printf("%s\n", line);
	while (line)
	{
		map_lines = ft_str_join(map_lines, line);
		line = get_next_line(mapfd);
		count++;
	}
	printf("%s\n", map_lines);
	return (0);
}
