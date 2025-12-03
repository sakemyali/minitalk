/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:41:41 by mosakura          #+#    #+#             */
/*   Updated: 2025/12/02 14:34:05 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	long long		res;
	size_t			i;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (res > ((LONG_MAX - (nptr[i] - '0')) / 10) && sign == -1)
			return ((int)LONG_MIN);
		if (res > ((LONG_MAX - (nptr[i] - '0')) / 10) && sign == 1)
			return ((int)LONG_MAX);
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * ((int)res));
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*mod;

	mod = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		mod[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
