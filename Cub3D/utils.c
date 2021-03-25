#include "cub3d.h"

void	xpm_to_image(void *mlx, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->img_width,
									&img->img_height);
	img->addr = (void *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
									&img->line_length, &img->endian);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_floor_ceil(t_all *all, int width, int high)
{
	int x;
	int y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < high)
		{
			if (y < (high / 2))
				my_mlx_pixel_put(all->mlx, x, y, all->file->ceilling);
			if (y >= (high / 2))
				my_mlx_pixel_put(all->mlx, x, y, all->file->floor);
			y++;
		}
		x++;
	}
}

void	sorting_sprite(t_all *all)
{
	t_sprite	tmp;
	int			x;
	int			cnt;

	x = 0;
	cnt = all->file->sp_num - 1;
	while (cnt > 0)
	{
		x = 0;
		while (x < all->file->sp_num)
		{
			if (all->mlx->sprt[x].dist < all->mlx->sprt[x + 1].dist)
			{
				tmp = all->mlx->sprt[x];
				all->mlx->sprt[x] = all->mlx->sprt[x + 1];
				all->mlx->sprt[x + 1] = tmp;
			}
			x++;
		}
		cnt--;
	}
}
