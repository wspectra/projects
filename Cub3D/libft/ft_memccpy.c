#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	ptr1 = (unsigned char*)d;
	ptr2 = (unsigned char*)s;
	if (!n)
		return (NULL);
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		if (ptr2[i] == (unsigned char)c)
			return ((char*)d + i + 1);
		i++;
	}
	return (NULL);
}
