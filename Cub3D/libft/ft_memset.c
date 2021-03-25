#include <stdio.h>

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char	*ptr1;
	size_t			i;

	i = 0;
	ptr1 = (unsigned char*)dst;
	while (i < n)
	{
		ptr1[i] = (unsigned char)c;
		i++;
	}
	return (dst);
}
