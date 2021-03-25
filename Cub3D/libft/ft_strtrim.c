#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && i > start)
		i--;
	end = i;
	if (!(str = ft_substr(s1, start, end - start + 1)))
		return (NULL);
	return (str);
}
