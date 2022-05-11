/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:52:21 by mgulenay          #+#    #+#             */
/*   Updated: 2021/12/09 19:54:42 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new_str = (char *)malloc(i + j + 1);
	if (!new_str)
		return (0);
	new_str[i + j] = '\0';
	ft_memmove(new_str, s1, i);
	ft_memmove(&new_str[i], s2, j);
	return (new_str);
}
