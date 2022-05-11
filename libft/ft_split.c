/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:08:56 by mgulenay          #+#    #+#             */
/*   Updated: 2021/12/08 14:06:26 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	count_length(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int
	find_end(const char *s, int e, int c)
{
	int	i;

	i = 0;
	if ((s[e]) == 0)
		return (0);
	while (s[e])
	{
		if (s[e] == c)
		{
			return (i);
		}
		e++;
		i++;
	}
	return (i);
}

static void
	array(char **new_array, char const *s, char c, int length)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	j = 0;
	while (length > 0)
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j] && s[j] != c)
		{
			end = find_end(s, j, c);
			new_array[i] = ft_substr(s, j, end);
			if (!new_array[i])
				free(new_array[i]);
			i++;
			j += end;
		}
		length--;
	}
}

char
	**ft_split(char const *s, char c)
{
	char	**new_array;
	int		length;

	if (!s)
		return (NULL);
	length = count_length(s, c);
	new_array = (char **)malloc(sizeof(char *) * (length + 1));
	if (!new_array)
		return (NULL);
	new_array[length] = 0;
	array(new_array, s, c, length);
	return (new_array);
}
