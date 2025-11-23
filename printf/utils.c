/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:54:19 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/23 14:54:28 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(const char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

void	ft_putstr(const char *s)
{
	size_t	slen;
	size_t	total;
	ssize_t	pdone;

	if (!s)
	{
		write(STDOUT_FILENO, "(null)", 6);
		return ;
	}
	slen = ft_strlen(s);
	total = 0;
	while (slen - total > WRITE_MAX)
	{
		pdone = write(STDOUT_FILENO, s + total, WRITE_MAX);
		if (pdone < 0)
			return ;
		total += (size_t)pdone;
	}
	if (slen > total)
		write(STDOUT_FILENO, s + total, slen - total);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int n)
{
	long	nb;
	char	ch;

	nb = n;
	if (nb < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr((int)(nb / 10));
	ch = (char)((nb % 10) + '0');
	write(STDOUT_FILENO, &ch, 1);
}

size_t	nbrlen(long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}
