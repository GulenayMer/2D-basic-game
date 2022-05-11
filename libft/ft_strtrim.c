/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:20:56 by mgulenay          #+#    #+#             */
/*   Updated: 2021/12/09 18:42:26 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	ft_check(char c, char const *chars)
{
	size_t	i;

	i = 0;
	while (chars[i] != '\0')
	{
		if (chars[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char
	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	size_t	start;
	size_t	end;

	if (!set || !s1)
		return (0);
	start = 0;
	while (s1[start] != '\0' && ft_check(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	if (start == end + 1)
	{
		str_trim = malloc(1);
		str_trim[0] = 0;
		return (str_trim);
	}
	while (s1[end] && s1[start] && ft_check(s1[end], set))
		end--;
	str_trim = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str_trim)
		return (0);
	ft_strlcpy(str_trim, &s1[start], end - start + 2);
	return (str_trim);
}
