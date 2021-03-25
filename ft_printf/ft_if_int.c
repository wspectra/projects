#include "ft_printf.h"

static void	ft_put_int(t_strt *strt, long int nb, int len)
{
	ft_put_prec(strt, len);
	ft_putnbr(nb, strt->type);
	strt->count = strt->count + len;
}

static void	ft_int_exeption(t_strt *strt, int len)
{
	if (strt->width > 0)
		ft_put_space(strt, len);
}

static void	ft_put_minus(int minus)
{
	if (minus == 1)
		write(1, "-", 1);
}

static void	ft_int_width(t_strt *strt, int len, long int nb, int minus)
{
	if (strt->minus && strt->width > 0)
	{
		ft_put_minus(minus);
		ft_put_int(strt, nb, len);
		ft_put_space(strt, len);
	}
	else if (strt->zero == 1 && strt->precision <= -1)
	{
		ft_put_minus(minus);
		ft_put_zero(strt, len);
		ft_put_int(strt, nb, len);
	}
	else if (strt->width > 0)
	{
		ft_put_space(strt, len);
		ft_put_minus(minus);
		ft_put_int(strt, nb, len);
	}
}

void		ft_if_int(t_strt *strt)
{
	long int	nb;
	int			len;
	int			minus;

	minus = 0;
	len = 0;
	nb = (int)va_arg(strt->ap, int);
	if (nb < 0)
	{
		minus = 1;
		nb = -nb;
		len = 1;
		if (strt->precision != -1)
			strt->precision++;
	}
	len = len + ft_len_numb(nb, strt->type);
	if (strt->precision == 0 && nb == 0)
		ft_int_exeption(strt, 0);
	else if (strt->width > 0)
		ft_int_width(strt, len, nb, minus);
	else
	{
		ft_put_minus(minus);
		ft_put_int(strt, nb, len);
	}
}
