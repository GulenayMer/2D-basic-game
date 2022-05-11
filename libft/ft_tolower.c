/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:19:23 by mgulenay          #+#    #+#             */
/*   Updated: 2021/12/09 18:57:12 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	ft_isupper(int c)
{
	return ((c >= 'A' && c <= 'Z'));
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
	{
		c += 32;
	}
	return (c);
}
