#include "ft_printf.h"

void	ft_put_zero(t_strt *strt, int len)
{
	int n;

	n = strt->width - len;
	while (n > 0)
	{
		write(1, "0", 1);
		strt->count++;
		n--;
	}
}

void	ft_put_space(t_strt *strt, int len)
{
	int n;

	if (strt->type == 'p')
		strt->width = strt->width - 2;
	if (strt->type == '%' || strt->type == 'c' || strt->type == 's')
		strt->precision = -1;
	if (strt->precision != -1 && strt->precision > len)
		n = strt->width - strt->precision;
	else
		n = strt->width - len;
	while (n > 0)
	{
		write(1, " ", 1);
		strt->count++;
		n--;
	}
}

void	ft_put_prec(t_strt *strt, int len)
{
	if (len < strt->precision && strt->precision != -1)
	{
		while (len != strt->precision)
		{
			write(1, "0", 1);
			strt->count++;
			len++;
		}
	}
}

void	ft_putchar(unsigned long int n, char type)
{
	if (type == 0)
	{
		write(1, &n, 1);
		return ;
	}
	if (n < 10)
		n = n + 48;
	else if (type == 'X')
		n = n + 55;
	else if (type == 'x' || type == 'p')
		n = n + 87;
	write(1, &n, 1);
}

void	ft_putnbr(unsigned long int n, char type)
{
	unsigned long int div;

	if (type == 'x' || type == 'X' || type == 'p')
		div = 16;
	else
		div = 10;
	if (n >= div)
	{
		ft_putnbr(n / div, type);
		ft_putchar((n % div), type);
	}
	else
		ft_putchar(n, type);
}
