/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:31:45 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/14 21:24:09 by mgulenay         ###   ########.fr       */
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

/* check if the first line is filled with 1s */
int	check_first_line(t_solong *game)
{
	int	i;
	int j;
	
	j = 0;
	i = 0;
	while (i < game->img_width)
	{
		if (game->map[j][i] != '1')
		{
			printf("firs row has no walls\n");
			return (1);
		}
		i++;
	}
	printf("walls\n");
	return (0);	
}

/* check if the last line is filled with 1s */
int	check_last_line(t_solong *game)
{
	int	i;
	int j;

	j = game->img_height - 1;
	//printf("%d\n", j);
	i = 0;
	while (i < game->img_width)
	{
		if (game->map[j][i] != '1')
		{
			printf("last row has no walls\n");
			return (1);
		}
		i++;
	}
	printf("walls\n");
	return (0);
}

/* check if the first indexes of the lines are filled with 1s */
int	check_first_index(t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->img_height)
	{
		if (game->map[j][i] != '1')
		{
			printf("first indexes have no walls\n");
			return (1);
		}
		j++;
	}
	printf("walls\n");
	return (0);
}

/* check if the last indexes of the lines are filled with 1s */
int	check_last_index(t_solong *game)
{
	int	i;
	int	j;

	i = game->img_width - 1;
	j = 0;
	while (j < game->img_height)
	{
		if (game->map[j][i] != '1')
		{
			printf("last indexes have no walls\n");
			return (1);
		}
		j++;
	}
	printf("walls\n");
	return (0);
}

/* check if at least one p, c and e exist */
int	check_p_c_e(t_solong *game)
{
	int	i;
	int	j;

	j = 1;
	while (j < game->img_height - 1)
	{
		i = 0;
		while (i < game->img_width)
		{
			if (game->map[j][i] == 'P')
			{
				printf("at least 1 P\n");
				game->player++;
			}
			if (game->map[j][i] == 'C')
			{
				printf("at least 1 C\n");
				game->collectible++;
			}
			if (game->map[j][i] == 'E')
			{
				printf("at least 1 E\n");
				game->exit++;
			}
			i++;
		}
		j++;
	}
	if (game->player == 0 || game->collectible == 0 || game->exit == 0)
	{
		printf("no p, e, or c\n");
		return (0);
	}
	return (1);
}

/* check if only p, c, e, 1 and 0 exist */
int	check_p_c_e_1_0(t_solong *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->img_height)
	{
		i = 0;
		while (i < game->img_width)
		{
			if (game->map[j][i] != 'P' && game->map[j][i] != 'E' && game->map[j][i] != 'C'
				&& game->map[j][i] != '1' && game->map[j][i] != '0')
			{
				printf("other chars\n");
				return (0);
			}
			i++;
		}
		j++;
	}
	printf("only P, E, C, 1 & 0\n");
	return (1);
}

/* check if the map is rectangular */
/*int	check_rectangular(t_solong *game)
{
	int	i;
	int	j;

	if (!(game->img_height < game->img_width))
	{
		printf("not a retangular\n");
		return (0);
	}





	printf("not a retangular\n");
	return (0);
}
*/