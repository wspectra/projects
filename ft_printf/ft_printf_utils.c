#include "ft_printf.h"

int		ft_len_numb(unsigned long n, char type)
{
	int					size;
	unsigned long int	div;

	size = 0;
	if (type == 'x' || type == 'X' || type == 'p')
		div = 16;
	else
		div = 10;
	while (n >= div)
	{
		size++;
		n = n / div;
	}
	return (size + 1);
}

int		ft_strlen(const char *str, int prec)
{
	size_t i;

	if (!str)
	{
		if (prec >= 0 && prec < 6)
			return (prec);
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(t_strt *strt, int len, char *str)
{
	int i;

	i = 0;
	while (len > 0)
	{
		ft_putchar(str[i], 0);
		len--;
		i++;
		strt->count++;
	}
}
