#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char*)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
