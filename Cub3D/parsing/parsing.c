#include "./../cub3d.h"

static int	size_of_file(char **file)
{
	int i;

	i = 0;
	while (file[i] != NULL)
		i++;
	return (i);
}

static int	check_errors(t_file *file)
{
	if (file->error == 1 || file->resol_x == 0 || file->north == NULL ||
			!file->west || file->east == NULL || file->south == NULL ||
			file->sprite == NULL || file->ceilling == -1 || file->map == NULL ||
			file->floor == -1)
	{
		write(1, "Error\nInvalid map data\n", 23);
		return (1);
	}
	return (0);
}

static void	check_lines(char **file, t_all *all)
{
	int		x;
	int		y;

	y = 0;
	while (file[y] != NULL)
	{
		x = 0;
		while (file[y][x] == ' ')
			x++;
		if (file[y][x] == 'R')
			check_resolution_validity(all->file, file[y], x);
		else if (ft_strchr("NSWE", (int)file[y][x]))
			check_path_validity(all->file, file[y], x);
		else if (file[y][x] == 'F' || file[y][x] == 'C')
			check_colors_validity(all->file, file[y], x, file[y][x]);
		else if (file[y][x] == '1')
			check_map_validity(all, &y, size_of_file(file), file);
		else if (file[y][x] != '\0')
		{
			all->file->error = 1;
			break ;
		}
		y++;
	}
}

void		parsing(char **file, int save)
{
	t_all	all;

	make_file_structure(&all);
	all.file->save = save;
	check_lines(file, &all);
	if (check_errors(all.file) != 1)
	{
		make_game(&all);
	}
	delete_structure_file(&all);
}
