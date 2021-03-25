#include "ft_printf.h"

static void	ft_put_pointer(t_strt *strt, unsigned long int nb, int len)
{
	ft_put_prec(strt, len);
	ft_putnbr(nb, strt->type);
	strt->count = strt->count + len + 2;
}

static void	ft_pointer_exeption(t_strt *strt, int len)
{
	if (strt->minus && strt->width > 0)
	{
		write(1, "0x", 2);
		ft_put_space(strt, len);
	}
	else if (strt->width > 0)
	{
		ft_put_space(strt, len);
		write(1, "0x", 2);
	}
	else
	{
		write(1, "0x", 2);
	}
	strt->count = strt->count + len + 2;
}

static void	ft_pointer_width(t_strt *strt, int len, unsigned long int nb)
{
	if (strt->minus && strt->width > 0)
	{
		write(1, "0x", 2);
		ft_put_pointer(strt, nb, len);
		ft_put_space(strt, len);
	}
	else if (strt->zero && strt->precision <= -1)
	{
		ft_put_zero(strt, len);
		write(1, "0x", 2);
		ft_put_pointer(strt, nb, len);
	}
	else if (strt->width > 0)
	{
		ft_put_space(strt, len);
		write(1, "0x", 2);
		ft_put_pointer(strt, nb, len);
	}
}

void		ft_if_pointer(t_strt *strt)
{
	unsigned long int	nb;
	int					len;

	nb = va_arg(strt->ap, unsigned long int);
	len = ft_len_numb(nb, strt->type);
	if (nb == 0 && strt->precision == 0)
		ft_pointer_exeption(strt, 0);
	else if (strt->width > 0)
		ft_pointer_width(strt, len, nb);
	else
	{
		write(1, "0x", 2);
		ft_put_pointer(strt, nb, len);
	}
}
