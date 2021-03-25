
#include "libft.h"

size_t		ft_find_enter(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int			ft_get_line(char **line, char **str)
{
	char	*tmp;

	if (!(*line = ft_substr(*str, 0, ft_find_enter(*str))))
		return (-1);
	if (!(tmp = ft_substr(*str, ft_find_enter(*str) + 1,
			(ft_strlen(*str) - ft_find_enter(*str)))))
		return (-1);
	free(*str);
	*str = tmp;
	return (1);
}

int			ft_get_line2(int fd, char **line, char **str, int b)
{
	char	*buf;
	char	*tmp;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((b = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[b] = '\0';
		tmp = ft_strjoin(*str, buf);
		free(*str);
		*str = tmp;
		if (ft_strchr(*str, '\n'))
		{
			free(buf);
			return (ft_get_line(line, str));
		}
	}
	free(buf);
	if (b < 0 || !(*line = ft_substr(*str, 0, ft_strlen(*str))))
		return (-1);
	free(*str);
	*str = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*str;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!str)
	{
		if (!(str = (char *)malloc(sizeof(char))))
			return (-1);
		str[0] = '\0';
	}
	if (ft_strchr(str, '\n'))
		return (ft_get_line(line, &str));
	return (ft_get_line2(fd, line, &str, 0));
}
