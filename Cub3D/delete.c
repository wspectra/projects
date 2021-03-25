#include "cub3d.h"

void	delete_file(char **file)
{
	int i;

	i = 0;
	while (file[i] != NULL)
	{
		free(file[i]);
		file[i] = NULL;
		i++;
	}
	free(file);
	file = NULL;
}

void	delete_lsts(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		(*lst) = tmp;
	}
	free(*lst);
	lst = NULL;
}

void	delete_structure_file(t_all *all)
{
	free(all->file->north);
	all->file->north = NULL;
	free(all->file->south);
	all->file->south = NULL;
	free(all->file->west);
	all->file->west = NULL;
	free(all->file->east);
	all->file->east = NULL;
	free(all->file->sprite);
	all->file->sprite = NULL;
	if (all->file->map)
		delete_file(all->file->map);
	free(all->file);
	all->file = NULL;
}

void	delete_mlx_struct(t_all *all)
{
	free(all->plr);
	free(all->mlx->west->addr);
	free(all->mlx->east->addr);
	free(all->mlx->south->addr);
	free(all->mlx->north->addr);
	free(all->mlx->sprite->addr);
	free(all->mlx->sprite->addr);
	free(all->mlx->west->img);
	free(all->mlx->east->img);
	free(all->mlx->south->img);
	free(all->mlx->north->img);
	free(all->mlx->sprite->img);
	free(all->mlx->sprite);
	free(all->mlx->west);
	free(all->mlx->east);
	free(all->mlx->south);
	free(all->mlx->north);
	free(all->mlx->map);
	free(all->mlx->mlx);
	free(all->mlx->win);
	free(all->mlx->img);
	free(all->mlx->addr);
	free(all->mlx);
}
