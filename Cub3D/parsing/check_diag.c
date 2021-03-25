#include "./../cub3d.h"

int	check_up_left(char **map, int x, int y)
{
	while (((int)ft_strlen(map[y]) > x) && ft_strchr("02NSWE", map[y][x]) &&
	y > 0 && x > 0)
	{
		y--;
		x--;
	}
	if (ft_strlen(map[y]) == (size_t)-1)
		return (1);
	if (map[y][x] != '1')
		return (1);
	return (0);
}

int	check_down_left(int size, char **map, int x, int y)
{
	while (((int)ft_strlen(map[y]) > x) && y < size && x > 0 &&
			ft_strchr("02NSWE", map[y][x]))
	{
		y++;
		x--;
	}
	if (ft_strlen(map[y]) == (size_t)-1)
		return (1);
	if (map[y][x] != '1')
		return (1);
	return (0);
}

int	check_up_right(char **map, int x, int y)
{
	while (((int)ft_strlen(map[y]) > x) && ft_strchr("02NSWE", map[y][x])
	&& y > 0)
	{
		y--;
		x++;
	}
	if (ft_strlen(map[y]) == (size_t)-1)
		return (1);
	if (map[y][x] != '1')
		return (1);
	return (0);
}

int	check_down_right(int size, char **map, int x, int y)
{
	while (((int)ft_strlen(map[y]) > x) && y < size &&
			ft_strchr("02NSWE", map[y][x]))
	{
		y++;
		x++;
	}
	if (ft_strlen(map[y]) == (size_t)-1)
		return (1);
	if (map[y][x] != '1')
		return (1);
	return (0);
}

int	check_diag(char **map, int x, int y, int size)
{
	int up_left;
	int down_left;
	int up_right;
	int down_right;

	up_left = check_up_left(map, x, y);
	down_left = check_down_left(size, map, x, y);
	up_right = check_up_right(map, x, y);
	down_right = check_down_right(size, map, x, y);
	if (up_left == 0 && down_left == 0 && up_right == 0 && down_right == 0)
		return (0);
	return (1);
}
