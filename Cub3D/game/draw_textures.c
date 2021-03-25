#include "./../cub3d.h"

void	what_pixel(t_img *img, t_all *all, int hig, t_pixel *pixel)
{
	if (all->plr->side == 0)
		pixel->wall = all->plr->pos_y
			+ all->plr->wall_dist * all->plr->ray_dir_y;
	else
		pixel->wall = all->plr->pos_x
			+ all->plr->wall_dist * all->plr->ray_dir_x;
	pixel->wall -= floor(pixel->wall);
	pixel->x = (int)(pixel->wall * img->img_height);
	if ((all->plr->side == 0 && all->plr->ray_dir_x > 0)
			|| (all->plr->side == 1 && all->plr->ray_dir_y < 0))
		pixel->x = img->img_height - pixel->x - 1;
	pixel->step = 1.0 * img->img_height / all->plr->hight_line;
	pixel->pos = (all->plr->start_line - hig / 2
			+ all->plr->hight_line / 2) * pixel->step;
}

t_img	*what_texture(t_all *all)
{
	if (all->plr->side == 1 && all->plr->ray_dir_y > 0)
		return (all->mlx->south);
	else if (all->plr->side == 1 && all->plr->ray_dir_y < 0)
		return (all->mlx->north);
	else if (all->plr->side == 0 && all->plr->ray_dir_x > 0)
		return (all->mlx->west);
	else
		return (all->mlx->east);
}

void	draw_textures(t_all *all, int j, int hig)
{
	t_pixel		pixel;
	int			i;
	int			color;
	int			*dst;
	t_img		*image;

	image = what_texture(all);
	all->mlx->pixel = &pixel;
	what_pixel(image, all, hig, &pixel);
	i = all->plr->start_line;
	while (i < all->plr->end_line)
	{
		pixel.y = (int)pixel.pos & (image->img_width - 1);
		pixel.pos += pixel.step;
		dst = (void *)image->addr + (pixel.y * image->line_length +
				pixel.x * (image->bits_per_pixel / 8));
		color = *(int*)dst;
		my_mlx_pixel_put(all->mlx, j, i, color);
		i++;
	}
}
