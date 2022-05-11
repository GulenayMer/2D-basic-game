/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:13:19 by mgulenay          #+#    #+#             */
/*   Updated: 2021/12/10 10:06:48 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	
	ft_putnumber(long number, int c, char *s)
{
	if (number < 0)
	{
		s[0] = '-';
		number = -number;
		s++;
		s[c] = 0;
	}
	while (--c >= 0)
	{
		s[c] = (number % 10) + '0';
		number = number / 10;
	}
}

static long int
	ft_length(long int number)
{
	int	len_count;

	len_count = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		number = -number;
	while (number > 0)
	{
		number = number / 10;
		len_count++;
	}
	return (len_count);
}

char
	*ft_itoa(int n)
{
	char	*str;
	size_t	length;
	long	number;

	number = n;
	length = ft_length(number);
	if (number < 0)
	{
		str = malloc(sizeof(char) * (length + 2));
		if (!str)
			return (0);
	}
	else
	{
		str = malloc(sizeof(char) * (length + 1));
		if (!str)
			return (0);
		str[length] = 0;
	}
	ft_putnumber(number, length, str);
	return (str);
}
