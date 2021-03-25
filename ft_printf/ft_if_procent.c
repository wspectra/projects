#include "ft_printf.h"

void	ft_if_procent(t_strt *strt)
{
	if (strt->width > 0)
	{
		if (strt->minus)
		{
			ft_putchar('%', 0);
			ft_put_space(strt, 1);
		}
		else if (strt->zero)
		{
			ft_put_zero(strt, 1);
			ft_putchar('%', 0);
		}
		else
		{
			ft_put_space(strt, 1);
			ft_putchar('%', 0);
		}
	}
	else
	{
		ft_putchar('%', 0);
	}
	strt->count++;
}
