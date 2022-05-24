/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:23:44 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/24 15:46:05 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mem_move(char *dest, char *src, size_t len)
{
	char	*p_dst;
	char	*p_src;
	size_t	i;

	p_dst = dest;
	p_src = src;
	i = 0;
	if (!dest && !src)
		return (0);
	if (p_dst > p_src)
		while (len-- > 0)
			p_dst[len] = p_src[len];
	else
	{
		while (i < len)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	return (dest);
}
