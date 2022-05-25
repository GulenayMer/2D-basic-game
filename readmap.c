/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:13:32 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/25 13:45:31 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_number_lines(char **argv)
{
	char	*line;
	int		mapfd;
	int		line_count;

	mapfd = open(argv[1], O_RDONLY);
	line = get_next_line(mapfd);
	line_count = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(mapfd);
		line_count++;
	}
	close(mapfd);
	return (line_count);
}

int	count_line_length(char **argv)
{
	char	*line;
	int		mapfd;
	int		line_length;

	mapfd = open(argv[1], O_RDONLY);
	line = get_next_line(mapfd);
	line_length = ft_strlen(line);
	free(line);
	close(mapfd);
	return (line_length);
}

void	ft_read_map(char **argv, t_solong *game)
{
	char	*line;
	int		mapfd;
	int		line_count;

	mapfd = open(argv[1], O_RDONLY);
	if (mapfd < 0)
	{
		write(1, "There is no such a file\n", 25);
		close(mapfd);
	}
	line_count = count_number_lines(argv);
	game->map = (char **)malloc(sizeof(t_solong *) * line_count - 1);
	if (!game->map)
		ft_free(game);
	line_count = 0;
	line = get_next_line(mapfd);
	while (line != NULL)
	{
		game->map[line_count] = line;
		line = get_next_line(mapfd);
		line_count++;
	}
	game->map_width = count_line_length(argv) - 1;
	game->map_height = line_count;
}
