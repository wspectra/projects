#include "ft_printf.h"

static void	ft_put_string(t_strt *strt, char *str, int len, int bytes)
{
	if (!str)
	{
		if (bytes < 6 && bytes >= 0)
		{
			strt->count = strt->count + bytes;
			write(1, "(null)", bytes);
		}
		else
		{
			strt->count = strt->count + 6;
			write(1, "(null)", 6);
		}
	}
	else
		ft_putstr(strt, len, str);
}

static void	ft_width_string(t_strt *strt, int len, char *str, int bytes)
{
	if (strt->minus && strt->width > 0)
	{
		ft_put_string(strt, str, len, bytes);
		ft_put_space(strt, len);
	}
	else if (strt->zero && strt->width > 0)
	{
		ft_put_zero(strt, len);
		ft_put_string(strt, str, len, bytes);
	}
	else if (strt->width > 0)
	{
		ft_put_space(strt, len);
		ft_put_string(strt, str, len, bytes);
	}
}

void		ft_if_string(t_strt *strt)
{
	char	*str;
	int		len;
	int		bytes;

	str = (char*)va_arg(strt->ap, char*);
	bytes = strt->precision;
	len = ft_strlen(str, strt->precision);
	if (len > strt->precision && strt->precision >= 0)
		len = strt->precision;
	if (strt->width > 0)
		ft_width_string(strt, len, str, bytes);
	else
		ft_put_string(strt, str, len, bytes);
}
