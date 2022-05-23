/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:13:32 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/23 21:55:38 by mgulenay         ###   ########.fr       */
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
	while (line)
	{
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
	line = get_next_line(mapfd);
	while (line)
	{
		game->map[line_count] = line;
		line = get_next_line(mapfd);
		line_count++;
	}
	game->map_width = count_line_length(argv) - 1;
	game->map_height = line_count;
}
