/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:51:39 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/23 14:54:25 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	getformattype(const char c, va_list list)
{
	if (c == 'c')
		return (print_char(list));
	else if (c == 's')
		return (print_str(list));
	else if (c == 'p')
		return (print_voidp(list));
	else if (c == 'd' || c == 'i')
		return (print_int(list));
	else if (c == 'u')
		return (print_uint(list));
	else if (c == 'x')
		return (print_hex(list, 0));
	else if (c == 'X')
		return (print_hex(list, 1));
	else if (c == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else
		return (0);
}

static size_t	parsing(const char *str, va_list list)
{
	size_t	i;
	size_t	total_len;

	i = 0;
	total_len = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			total_len++;
			i++;
		}
		if (str[i] == '%' && !str[i + 1])
			return (total_len);
		if (str[i] == '%' && str[i + 1])
		{
			total_len += getformattype(str[i + 1], list);
			i += 2;
		}
	}
	return (total_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	size_t	total_len;

	if (!str)
		return (0);
	total_len = 0;
	va_start(list, str);
	total_len = parsing(str, list);
	va_end(list);
	return ((int)total_len);
}
