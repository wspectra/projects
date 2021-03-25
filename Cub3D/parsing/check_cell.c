#include "./../cub3d.h"

int	check_up(char **map, int x, int y)
{
	while (((int)ft_strlen(map[y]) > x) && ft_strchr("02NSWE",
											map[y][x]) && y > 0)
	{
		y--;
	}
	if (ft_strlen(map[y]) == (size_t)-1)
		return (1);
	if (map[y][x] != '1')
		return (1);
	return (0);
}

int	check_down(int size, char **map, int x, int y)
{
	while (((int)ft_strlen(map[y]) > x) && y < size &&
			ft_strchr("02NSWE", map[y][x]))
	{
		y++;
	}
	if (ft_strlen(map[y]) == (size_t)-1)
		return (1);
	if (map[y][x] != '1')
		return (1);
	return (0);
}

int	check_left(char **map, int x, int y)
{
	while (x > 0 && ft_strchr("02NSWE", map[y][x]))
	{
		x--;
	}
	if (map[y][x] == '1')
		return (0);
	return (1);
}

int	check_right(char **map, int x, int y)
{
	while (ft_strchr("02NSWE", map[y][x]))
	{
		x++;
	}
	if (map[y][x] == '1')
		return (0);
	return (1);
}

int	check_cell(char **map, int x, int y)
{
	int up;
	int down;
	int left;
	int right;
	int size;

	size = 0;
	while (map[size] != NULL)
		size++;
	up = check_up(map, x, y);
	down = check_down(size, map, x, y);
	left = check_left(map, x, y);
	right = check_right(map, x, y);
	if (up == 0 && down == 0 && left == 0 && right == 0
	&& check_diag(map, x, y, size) == 0)
		return (0);
	return (1);
}
