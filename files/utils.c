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
