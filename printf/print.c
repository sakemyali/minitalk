/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:53:49 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/23 14:54:27 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_char(va_list list)
{
	int		c;

	c = va_arg(list, int);
	ft_putchar((char)c);
	return (1);
}

size_t	print_int(va_list list)
{
	int		n;
	size_t	len;

	n = (va_arg(list, int));
	ft_putnbr(n);
	len = nbrlen(n);
	return (len);
}

size_t	print_str(va_list list)
{
	char	*str;
	size_t	len;

	str = va_arg(list, char *);
	if (!str)
		str = "(null)";
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

size_t	print_voidp(va_list list)
{
	void				*mem;
	unsigned long long	ull_mem;
	size_t				len;

	mem = va_arg(list, void *);
	if (!mem)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	ull_mem = (unsigned long long)mem;
	len = char_to_hex(ull_mem, "0123456789abcdef");
	return (2 + len);
}

size_t	print_hex(va_list list, const int x)
{
	const char		*x_digits;
	const char		*bigx_digits;
	unsigned int	nbr;
	size_t			len;

	len = 0;
	x_digits = "0123456789abcdef";
	bigx_digits = "0123456789ABCDEF";
	nbr = va_arg(list, unsigned int);
	if (x == 0)
		len = char_to_hex(nbr, x_digits);
	else
		len = char_to_hex(nbr, bigx_digits);
	return (len);
}
