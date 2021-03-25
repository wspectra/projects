#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*s2;

	a = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * a + 1);
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, (a + 1));
	return (s2);
}
