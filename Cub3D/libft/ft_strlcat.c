#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	len_dst;

	d = 0;
	s = 0;
	len_dst = ft_strlen(dest);
	if (size == 0)
		return (ft_strlen(src));
	if (len_dst <= size)
	{
		while (dest[d] != '\0')
			d++;
		while (d < size - 1 && src[s] != '\0')
		{
			dest[d] = src[s];
			d++;
			s++;
		}
		dest[d] = '\0';
		return (len_dst + ft_strlen(src));
	}
	return (ft_strlen(src) + size);
}
