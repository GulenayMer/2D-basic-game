/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:59:46 by mgulenay          #+#    #+#             */
/*   Updated: 2021/12/10 00:20:12 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	slength;
	size_t	dlength;

	slength = ft_strlen(src);
	dlength = ft_strlen(dst);
	j = dlength;
	i = 0;
	if (dlength < size - 1 && size > 0)
	{
		while (src[i] != '\0' && (dlength + i < size - 1))
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = '\0';
	}
	if (dlength >= size)
		dlength = size;
	return (dlength + slength);
}
