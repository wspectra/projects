#include "ft_printf.h"

static void	ft_struct_zero(t_strt *strt)
{
	strt->minus = 0;
	strt->zero = 0;
	strt->precision = -1;
	strt->type = '0';
	strt->width = 0;
}

static void	ft_write(const char *str, t_strt *strt)
{
	while (str[strt->i] != '%' && str[strt->i] != '\0')
	{
		ft_putchar(str[strt->i], 0);
		strt->i++;
		strt->count = strt->count + 1;
	}
}

int			ft_printf(const char *str, ...)
{
	t_strt	strt;

	va_start(strt.ap, str);
	strt.i = 0;
	strt.count = 0;
	while (str[strt.i] != '\0')
	{
		ft_struct_zero(&strt);
		ft_write(str, &strt);
		if (str[strt.i] == '%')
		{
			strt.i++;
			ft_parsing(str, &strt);
		}
	}
	va_end(strt.ap);
	return (strt.count);
}
