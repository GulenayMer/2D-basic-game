
/* The MAP  
	-- 's extension must be .BER  -- CHECKED
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
		1) extension !(ber)
		2) !(pce10)	
		3) !(surrounded by walls)
		("Error\n")
	*/

#include "so_long.h"

int	count_number_lines(char **argv)
{
	char	*line;
	int		mapfd;
	int		line_count;

	mapfd = open(argv[1], O_RDONLY);
	line = get_next_line(mapfd);
	line_count = 0;
	while (line)
	{
		line = get_next_line(mapfd);
		line_count++;
	}
	close(mapfd);
	return (line_count);
}

int count_line_length(char **argv)
{
	char	*line;
	int		mapfd;
	int		line_length;

	mapfd = open(argv[1], O_RDONLY);
	line = get_next_line(mapfd);
	line_length = ft_strlen(line);
	close(mapfd);
	return (line_length);
}

void	ft_read_map(char **argv, t_solong *game)
{
	char	*line;
	int		mapfd;
	int		line_count;

	mapfd = open(argv[1], O_RDONLY);
	line_count = count_number_lines(argv);
	game->map = (char **)malloc(sizeof(t_solong *) * line_count - 1);
	line_count = 0;
	while (line) 
	{
		line = get_next_line(mapfd);
		game->map[line_count] = line;
		line_count++;
	}
	//check_walls(map[line_count]);
	/* int i = 0;
	while (i < line_count && game->map[i])
	{
		printf("%s", game->map[i]);
		i++;
	} */
	game->img_width = count_line_length(argv) - 1;
	game->img_height = line_count - 1;
	//close(mapfd);
}

int error_check(t_solong *game)
{
	if (check_first_line(game) || check_last_line(game) || check_first_index(game)
		|| check_last_index(game) || check_p_c_e(game) || check_p_c_e_1_0(game))
	{
		write(1, "Error with the map\n", 20);
		return (1);
	}
	write(1, "no error with the map\n", 23);
	return (0);
}

int	main(int argc, char **argv)
{
	t_solong game;

	if (argc < 2)
		return (1);
	/*int line_count;
	line_count = count_lines(argv);
	printf("%d\n", line_count); */
	ft_read_map(argv, &game);
	error_check(&game);
	//printf("%d\n", game.img_width);
	//printf("%d\n", game.img_height);
	return (0);
}
