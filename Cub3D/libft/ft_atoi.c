#include "libft.h"

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	res;
	int					i;

	sign = 0;
	res = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	sign = str[i] == '-' ? -1 : 1;
	i = str[i] == '+' ? i + 1 : i;
	i = sign == -1 ? i + 1 : i;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - 48;
	if (res > 9223372036854775807)
		return (sign == 1 ? -1 : 0);
	return (res * sign);
}
