#include <strings.h>

void	*ft_bzero(void *dst, size_t n)
{
	unsigned char	*ptr1;
	size_t			i;

	i = 0;
	ptr1 = (unsigned char*)dst;
	while (i < n)
	{
		ptr1[i] = 0;
		i++;
	}
	return (dst);
}
