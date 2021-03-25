#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != c && i > 0)
		i--;
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
