#include "ft_printf.h"

static void	ft_put_hex(t_strt *strt, unsigned int nb, int len)
{
	ft_put_prec(strt, len);
	ft_putnbr(nb, strt->type);
	strt->count = strt->count + len;
}

static void	ft_hex_exeption(t_strt *strt, int len)
{
	if (strt->width > 0)
	{
		write(1, " ", 1);
		ft_put_space(strt, len);
		strt->count = strt->count + len;
	}
}

static void	ft_hex_width(t_strt *strt, int len, unsigned int nb)
{
	if (strt->minus && strt->width > 0)
	{
		ft_put_hex(strt, nb, len);
		ft_put_space(strt, len);
	}
	else if (strt->zero == 1 && strt->precision <= -1)
	{
		ft_put_zero(strt, len);
		ft_put_hex(strt, nb, len);
	}
	else
	{
		ft_put_space(strt, len);
		ft_put_hex(strt, nb, len);
	}
}

void		ft_if_hex(t_strt *strt)
{
	unsigned int	nb;
	int				len;

	nb = (unsigned int)va_arg(strt->ap, unsigned int);
	len = ft_len_numb(nb, strt->type);
	if (strt->precision == 0 && nb == 0)
		ft_hex_exeption(strt, len);
	else if (strt->width > 0)
		ft_hex_width(strt, len, nb);
	else
	{
		ft_put_hex(strt, nb, len);
	}
}
