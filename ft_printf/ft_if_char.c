#include "ft_printf.h"

void		ft_if_char(t_strt *strt)
{
	unsigned char c;

	c = (unsigned char)va_arg(strt->ap, int);
	if (strt->width > 0)
	{
		if (strt->minus)
		{
			ft_putchar(c, 0);
			ft_put_space(strt, 1);
		}
		else if (strt->zero)
		{
			ft_put_zero(strt, 1);
			ft_putchar(c, 0);
		}
		else
		{
			ft_put_space(strt, 1);
			ft_putchar(c, 0);
		}
	}
	else
		ft_putchar(c, 0);
	strt->count++;
}
