/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:52:59 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/23 14:56:45 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define WRITE_MAX 2147479552

int		ft_printf(const char *str, ...);
size_t	nbrlen(long n);
char	*ft_itoa(int n);
size_t	print_char(va_list list);
size_t	print_int(va_list list);
size_t	print_str(va_list list);
size_t	print_hex(va_list list, int x);
size_t	print_voidp(va_list list);
size_t	print_uint(va_list list);
size_t	char_to_hex(unsigned long long n, const char *x_digits);
size_t	ft_putchar(char c);
void	ft_putstr(const char *s);
size_t	ft_strlen(const char *str);
void	ft_putnbr(int n);

#endif
