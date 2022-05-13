#include "so_long.h"

int	count_lines(char **argv)
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

void	ft_read_map(char **argv)
{
	char	*line;
	int		mapfd;
	int		line_count;
	char	**map;

	mapfd = open(argv[1], O_RDONLY);

	line_count = count_lines(argv);
	map = (char **)malloc(sizeof(char *) * line_count);
	line_count = 0;
	while (line) 
	{
		line = get_next_line(mapfd);
		map[line_count] = line;
		line_count++;
	}
	int i = 0;
	while (i < line_count && map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	close(mapfd);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);

	int line_count;

	line_count = count_lines(argv);
	printf("%d\n", line_count);
	ft_read_map(argv);
	return (0);
}
