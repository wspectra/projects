#include "./../cub3d.h"

static int	path_len(const char *str, int i)
{
	int len;

	len = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char	what_type_texture(const char *str, int *i)
{
	char	c;
	int		k;

	k = *i;
	if (str[k] == 'N' && str[k + 1] == 'O' && str[k + 2] == ' ')
		c = 'N';
	else if (str[k] == 'S' && str[k + 1] == 'O' && str[k + 2] == ' ')
		c = 'S';
	else if (str[k] == 'W' && str[k + 1] == 'E' && str[k + 2] == ' ')
		c = 'W';
	else if (str[k] == 'E' && str[k + 1] == 'A' && str[k + 2] == ' ')
		c = 'E';
	else if (str[k] == 'S' && str[k + 1] == ' ')
		c = 'P';
	else
		c = 'X';
	if (c == 'P')
		*i = *i + 1;
	else
		*i = *i + 2;
	return (c);
}

static int	check_and_add_path(const char *path, char c, t_file *file)
{
	int fd;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (0);
	close(fd);
	if (c == 'N')
		file->north = ft_strdup(path);
	else if (c == 'S')
		file->south = ft_strdup(path);
	else if (c == 'W')
		file->west = ft_strdup(path);
	else if (c == 'E')
		file->east = ft_strdup(path);
	else if (c == 'P')
		file->sprite = ft_strdup(path);
	return (1);
}

static void	get_path(char *str, int *i, char c, t_file *file)
{
	char	*path;
	int		k;
	int		p;

	p = 0;
	k = *i;
	if (!(path = (char*)malloc(sizeof(char) * (path_len(str, k) + 1))))
		return ;
	while (str[k] != ' ' && str[k] != '\0')
	{
		path[p] = str[k];
		p++;
		k++;
	}
	path[p] = '\0';
	while (str[k] == ' ')
		k++;
	if (path[p - 1] != 'm' && path[p - 2] != 'p' && path[p - 3] != 'x'
		&& path[p - 4] != '.')
		file->error = 1;
	if (str[k] != '\0' || check_and_add_path(path, c, file) == 0)
		file->error = 1;
	free(path);
}

void		check_path_validity(t_file *file, char *str, int i)
{
	char	type;

	type = what_type_texture(str, &i);
	if (type == 'X' || (type == 'N' && file->north) ||
			(type == 'S' && file->south) || (type == 'P' && file->sprite) ||
			(type == 'E' && file->east) || (type == 'W' && file->west))
	{
		{
			file->error = 1;
			return ;
		}
	}
	while (str[i] == ' ')
		i++;
	get_path(str, &i, type, file);
}
