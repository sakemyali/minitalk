/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:54:04 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/23 14:54:27 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	put_signed(unsigned int u)
{
	size_t	len;

	len = 0;
	if (u >= 10)
		len += put_signed(u / 10);
	ft_putchar((char)('0' + (u % 10)));
	return (len + 1);
}

size_t	print_uint(va_list list)
{
	unsigned int	nbr;
	size_t			len;

	nbr = va_arg(list, unsigned int);
	len = put_signed(nbr);
	return (len);
}

size_t	char_to_hex(unsigned long long n, const char *x_digits)
{
	char		buffer[16];
	size_t		count;
	size_t		i;

	i = 0;
	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n)
	{
		buffer[i++] = x_digits[n & 0xF];
		n >>= 4;
	}
	while (i--)
	{
		ft_putchar(buffer[i]);
		count++;
	}
	return (count);
}
