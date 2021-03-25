#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, (len));
	*(str + len) = '\0';
	return (str);
}
