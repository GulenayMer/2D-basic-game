/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:00:20 by mgulenay          #+#    #+#             */
/*   Updated: 2021/12/09 17:58:23 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	ft_count_number(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void
	ft_put_number(long n, int c, char *s)
{
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
		s++;
		s[c] = 0;
	}
	while (--c >= 0)
	{
		s[c] = (n % 10) + '0';
		n = n / 10;
	}
}

void
	ft_putnbr_fd(int n, int fd)
{
	char	s[12];
	int		count;
	long	number;

	number = n;
	ft_bzero(s, 11);
	count = ft_count_number(number);
	ft_put_number(number, count, s);
	ft_putstr_fd(s, fd);
}
