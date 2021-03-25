#include "./../cub3d.h"

static char	**make_map(char **file, int start, int end)
{
	char	**map;
	int		i;

	if (!(map = (char **)malloc(sizeof(char *) * (end - start + 1))))
		return (NULL);
	i = 0;
	while (file[start] != NULL)
	{
		if (!(map[i] = ft_strdup(file[start])))
			return (NULL);
		i++;
		start++;
	}
	map[i] = NULL;
	return (map);
}

static void	check_lines(t_all *all, int x, int y)
{
	if (all->file->map[y][x] == '0' || all->file->map[y][x] == '2')
	{
		if (all->file->map[y][x] == '2')
			all->file->sp_num++;
		if (check_cell(all->file->map, x, y) != 0)
			all->file->error = 1;
	}
	else if (all->file->map[y][x] == 'N' || all->file->map[y][x] == 'W' ||
				all->file->map[y][x] == 'E' || all->file->map[y][x] == 'S')
	{
		if (all->file->plr == 1)
			all->file->error = 1;
		else
			all->file->plr = 1;
		if (check_cell(all->file->map, x, y) != 0)
			all->file->error = 1;
	}
	else if (all->file->map[y][x] != '1' && all->file->map[y][x] != ' ')
		all->file->error = 1;
	else
		return ;
}

void		check_map_validity(t_all *all, int *start_map, int size_file,
						char **file)
{
	int start;
	int x;
	int y;

	start = *start_map;
	all->file->sp_num = 0;
	if (all->file->error == 1)
		return ;
	if (!(all->file->map = make_map(file, start, size_file)))
		all->file->error = 1;
	y = 0;
	while (all->file->map[y] != NULL)
	{
		x = 0;
		while (all->file->map[y][x] != '\0')
		{
			check_lines(all, x, y);
			x++;
		}
		y++;
	}
	if (all->file->plr == 0)
		all->file->error = 1;
	*start_map = size_file - 1;
}
