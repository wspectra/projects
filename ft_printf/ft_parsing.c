#include "ft_printf.h"

static int	ft_int_to_char(const char *str, t_strt *strt)
{
	int nb;

	nb = 0;
	if (str[strt->i] == '*')
	{
		nb = va_arg(strt->ap, int);
		strt->i = strt->i + 1;
		return (nb);
	}
	while (str[strt->i] >= '0' && str[strt->i] <= '9' && str[strt->i] != '\0')
	{
		nb = nb * 10 + str[strt->i] - 48;
		strt->i++;
	}
	return (nb);
}

static void	ft_flags(const char *str, t_strt *strt)
{
	while (str[strt->i] == '0' || str[strt->i] == '-')
	{
		if (str[strt->i] == '-')
			strt->minus = 1;
		if (str[strt->i] == '0')
			strt->zero = 1;
		strt->i++;
	}
	if (strt->minus == 1)
		strt->zero = 0;
}

static void	ft_what_type(t_strt *strt)
{
	if (strt->type == 'c')
		ft_if_char(strt);
	else if (strt->type == 's')
		ft_if_string(strt);
	if (strt->type == 'p')
		ft_if_pointer(strt);
	else if (strt->type == 'd' || strt->type == 'i')
		ft_if_int(strt);
	else if (strt->type == 'u')
		ft_if_uns_int(strt);
	else if (strt->type == 'x' || strt->type == 'X')
		ft_if_hex(strt);
	else if (strt->type == '%')
		ft_if_procent(strt);
}

void		ft_parsing(const char *str, t_strt *strt)
{
	ft_flags(str, strt);
	if (str[strt->i] == ' ')
		write(1, " ", 1);
	while (str[strt->i] == ' ' && str[strt->i] != '\0')
		strt->i = strt->i + 1;
	strt->width = ft_int_to_char(str, strt);
	if (strt->width < 0)
	{
		strt->minus = 1;
		strt->width = strt->width * (-1);
		strt->zero = 0;
	}
	if (str[strt->i] == '.')
	{
		strt->i++;
		strt->precision = 0;
		strt->precision = ft_int_to_char(str, strt);
	}
	if (str[strt->i])
	{
		strt->type = str[strt->i];
		strt->i++;
	}
	ft_what_type(strt);
}
