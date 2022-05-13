/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:31:45 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/13 17:27:53 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* check if the map has ber extension */
int	check_ber(char *argv)
{
	int	argv_first_length;
	int	index;

	argv_first_length = ft_strlen(argv);
	index = argv_first_length - 1;
	if (argv[index] == 'r' && argv[index - 1] == 'e' && argv[index - 2] == 'b'
		 && argv[index - 3] == '.')
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

int	ft_str_chr(char *s, char c)
{
	int i;
	int length;

	length = ft_strlen(s);
	i = 0;
	while (i < length)
	{
		if (s[i] != c)
			return (0);
		i++;
	}
	return (1);
}


int	check_first_last_line(t_solong *game)
{
	int	i;

	i = 0;
	while (i < game->img_width && game->map[i])
	{
		if (!ft_str_chr(game->map[i], '1'))
		{
			printf("no walls");
			return (1);
		}
		i++;
		
	}
	/*i = 0;
	while (map[game->img_height - 1][i])
	{
		if (!ft_strchr(map[i], '1'))
		{
			printf("no walls");
			return (1);
		}
		i++;
	}*/
	return (0);	
}
