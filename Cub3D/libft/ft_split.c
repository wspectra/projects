#include "libft.h"

static int		ft_words_count(const char *str, const char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0' && str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] != c)
			i++;
		count++;
		while (str[i] != '\0' && str[i] == c)
			i++;
	}
	return (count);
}

static int		ft_word_length(char const *str, char c, int i)
{
	int	size;

	size = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static char		**ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		words;
	char	**arr;

	if (s == NULL)
		return (NULL);
	words = ft_words_count(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (words > 0)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (!(arr[k] = ft_substr(s, i, ft_word_length(s, c, i))))
			return (ft_free(arr));
		i = i + ft_word_length(s, c, i);
		k++;
		words--;
	}
	arr[k] = 0;
	return (arr);
}
