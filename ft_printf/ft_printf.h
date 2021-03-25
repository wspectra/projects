#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct	s_strt
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	char	type;
	int		i;
	int		count;
	va_list ap;
}				t_strt;

int				ft_printf(const char *str, ...);
int				ft_strlen(const char *str, int prec);
int				ft_len_numb(unsigned long n, char type);
char			*ft_strdup(const char *s1);
void			ft_parsing(const char *str, t_strt *strt);
void			ft_if_char(t_strt *strt);
void			ft_if_string(t_strt *strt);
void			ft_if_procent(t_strt *strt);
void			ft_if_pointer(t_strt *strt);
void			ft_if_int(t_strt *strt);
void			ft_if_uns_int(t_strt *strt);
void			ft_if_hex(t_strt *strt);
void			ft_put_zero(t_strt *strt, int len);
void			ft_put_space(t_strt *strt, int len);
void			ft_put_prec(t_strt *strt, int len);
void			ft_putchar(unsigned long int n, char type);
void			ft_putnbr(unsigned long int n, char type);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_putstr(t_strt *strt, int len, char *str);

#endif
