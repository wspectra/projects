#include "./../cub3d.h"

static int	find_number(char *str, int *i)
{
	int	k;
	int	res;

	k = *i;
	res = 0;
	while (str[k] == ' ')
		k++;
	while (ft_isdigit(str[k]) == 1 && res < 214748364)
		res = res * 10 + str[k++] - 48;
	if (res == 214748364 && str[k] <= '7')
		res = res * 10 + str[k++] - 48;
	if ((res == 214748364 && str[k + 1] > '7') ||
		(res > 214748364 && ft_isdigit(str[k]) == 1))
	{
		res = 2147483645;
		while (ft_isdigit(str[k]) == 1)
			k++;
	}
	while (str[k] == ' ')
		k++;
	*i = k;
	return (res);
}

void		check_resolution_validity(t_file *file, char *str, int i)
{
	int	value;

	if (str[++i] != ' ' || file->resol_x != 0 ||
		file->resol_y != 0 || file->error != 0)
	{
		file->error = 1;
		return ;
	}
	value = find_number(str, &i);
	file->resol_x = value;
	value = find_number(str, &i);
	file->resol_y = value;
	if (str[i] != '\0' || file->resol_x <= 0 ||
		file->resol_y <= 0)
		file->error = 1;
}
