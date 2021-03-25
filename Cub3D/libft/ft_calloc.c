#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *str;

	str = (char*)malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}
