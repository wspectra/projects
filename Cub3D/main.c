#include "cub3d.h"

static int	check_file_name_validity(char *str)
{
	int i;

	i = ft_strlen(str);
	if (str[i - 4] == '.' && str[i - 3] == 'c' && str[i - 2] == 'u'
		&& str[i - 1] == 'b' && str[i] == '\0')
		return (1);
	else
		return (0);
}

int			main(int argc, char *argv[])
{
	int fd;
	int save;

	save = 0;
	if (argc == 2 || argc == 3)
	{
		if (argc == 3 && ft_strncmp("--save", argv[2], 7) == 0)
			save = 1;
		if (argc == 3 && ft_strncmp("--save", argv[2], 7) != 0)
			save = -1;
		if (check_file_name_validity(argv[1]) == 1 && (save == 1 || save == 0))
		{
			if ((fd = open(argv[1], O_RDONLY)) < 0)
				write(1, "Error\nCouldn't read file\n", 24);
			else
				read_file(fd, save);
		}
		else
			write(1, "Error\nInvalid file name\n", 24);
	}
	else
		write(1, "Error\nWrong number of arguments\n", 33);
	return (0);
}
