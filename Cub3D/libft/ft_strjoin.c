#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(s3 = (char*)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_memcpy(s3, s1, len_s1);
	ft_memcpy((s3 + len_s1), s2, len_s2);
	*(s3 + len_s1 + len_s2) = '\0';
	return (s3);
}
