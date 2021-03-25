#include "./cub3d.h"

void	make_file_structure(t_all *all)
{
	t_file	*file;

	file = (t_file*)malloc(sizeof(t_file));
	file->resol_x = 0;
	file->resol_y = 0;
	file->north = 0x0;
	file->south = 0x0;
	file->west = 0x0;
	file->east = 0x0;
	file->sprite = 0x0;
	file->ceilling = -1;
	file->floor = -1;
	file->error = 0;
	file->map = 0x0;
	all->file = file;
}

void	sprite_struct_init(t_all *all)
{
	t_sprite	*sprite;
	int			x;
	int			y;
	int			z;

	sprite = (t_sprite*)malloc(sizeof(t_sprite) * (all->file->sp_num + 1));
	z = 0;
	y = 0;
	while (all->file->map[y] != NULL)
	{
		x = 0;
		while (all->file->map[y][x] != '\0')
		{
			x++;
			if (all->file->map[y][x] == '2')
			{
				sprite[z].pos_x = x + 0.5;
				sprite[z].pos_y = y + 0.5;
				z++;
			}
		}
		y++;
	}
	all->mlx->sprt = sprite;
}

void	make_img_struct(t_all *all)
{
	t_img *north;
	t_img *south;
	t_img *west;
	t_img *east;
	t_img *sprite;

	north = (t_img*)malloc(sizeof(t_img));
	south = (t_img*)malloc(sizeof(t_img));
	west = (t_img*)malloc(sizeof(t_img));
	east = (t_img*)malloc(sizeof(t_img));
	sprite = (t_img*)malloc(sizeof(t_img));
	all->mlx->sprite = sprite;
	all->mlx->west = west;
	all->mlx->east = east;
	all->mlx->south = south;
	all->mlx->north = north;
}

void	make_mlx_struct(t_all *all)
{
	t_mlx *mlx;
	t_plr *plr;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	plr = (t_plr*)malloc(sizeof(t_plr));
	all->mlx = mlx;
	all->plr = plr;
	all->mlx->map = all->file->map;
	make_img_struct(all);
}

void	make_images(t_all *all)
{
	xpm_to_image(all->mlx->mlx, all->mlx->north, all->file->north);
	xpm_to_image(all->mlx->mlx, all->mlx->west, all->file->west);
	xpm_to_image(all->mlx->mlx, all->mlx->east, all->file->east);
	xpm_to_image(all->mlx->mlx, all->mlx->south, all->file->south);
	xpm_to_image(all->mlx->mlx, all->mlx->sprite, all->file->sprite);
}
