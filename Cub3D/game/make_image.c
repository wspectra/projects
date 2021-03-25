#include "./../cub3d.h"

static void	start_end(t_all *all, int hig)
{
	if (all->plr->side == 0)
		all->plr->wall_dist = (all->plr->map_pos_x - all->plr->pos_x
			+ (double)(1 - all->plr->step_x) / 2) / all->plr->ray_dir_x;
	else
		all->plr->wall_dist = (all->plr->map_pos_y - all->plr->pos_y
			+ (double)(1 - all->plr->step_y) / 2) / all->plr->ray_dir_y;
	all->plr->hight_line = (int)(hig / all->plr->wall_dist);
	all->plr->start_line = -all->plr->hight_line / 2 + hig / 2;
	if (all->plr->start_line < 0)
		all->plr->start_line = 0;
	all->plr->end_line = all->plr->hight_line / 2 + hig / 2;
	if (all->plr->end_line >= hig)
		all->plr->end_line = hig;
}

static void	hit(t_all *all, int high)
{
	while (all->plr->hit == 0)
	{
		if (all->plr->side_x < all->plr->side_y)
		{
			all->plr->side_x += all->plr->delta_x;
			all->plr->map_pos_x += all->plr->step_x;
			all->plr->side = 0;
		}
		else
		{
			all->plr->side_y += all->plr->delta_y;
			all->plr->map_pos_y += all->plr->step_y;
			all->plr->side = 1;
		}
		if ((all->file->map[(int)floor(all->plr->map_pos_y)]
		[(int)floor(all->plr->map_pos_x)]) == '1')
			all->plr->hit = 1;
	}
	start_end(all, high);
}

static void	ray_dir(t_all *all, int high)
{
	if (all->plr->ray_dir_x < 0)
	{
		all->plr->step_x = -1;
		all->plr->side_x = (all->plr->pos_x - all->plr->map_pos_x)
			* all->plr->delta_x;
	}
	else
	{
		all->plr->step_x = 1;
		all->plr->side_x = (all->plr->map_pos_x + 1.0 - all->plr->pos_x)
			* all->plr->delta_x;
	}
	if (all->plr->ray_dir_y < 0)
	{
		all->plr->step_y = -1;
		all->plr->side_y = (all->plr->pos_y - all->plr->map_pos_y)
			* all->plr->delta_y;
	}
	else
	{
		all->plr->step_y = 1;
		all->plr->side_y = (all->plr->map_pos_y + 1.0 - all->plr->pos_y)
			* all->plr->delta_y;
	}
	hit(all, high);
}

int			draw_walls(t_all *all, int wid, int high)
{
	int		i;
	double	camera_x;

	if (!(all->plr->wall_dist_array = (double*)malloc(sizeof(double ) * wid)))
		return (all->file->error = -1);
	i = 0;
	while (i < wid)
	{
		all->plr->hit = 0;
		camera_x = 2 * i / (double)wid - 1;
		all->plr->ray_dir_x = all->plr->vector_x + all->plr->plan_x * camera_x;
		all->plr->ray_dir_y = all->plr->vector_y + all->plr->plan_y * camera_x;
		all->plr->map_pos_x = (int)floor(all->plr->pos_x);
		all->plr->map_pos_y = (int)floor(all->plr->pos_y);
		all->plr->delta_x = fabs(1 / all->plr->ray_dir_x);
		all->plr->delta_y = fabs(1 / all->plr->ray_dir_y);
		ray_dir(all, high);
		draw_textures(all, i, high);
		all->plr->wall_dist_array[i] = all->plr->wall_dist;
		i++;
	}
	return (1);
}

int			ft_make_image(t_all *all)
{
	all->mlx->img = mlx_new_image(all->mlx->mlx, all->plr->wid, all->plr->hig);
	all->mlx->addr = mlx_get_data_addr(all->mlx->img, &all->mlx->bits_per_pixel,
									&all->mlx->line_length, &all->mlx->endian);
	draw_floor_ceil(all, all->plr->wid, all->plr->hig);
	draw_walls(all, all->plr->wid, all->plr->hig);
	make_sprite(all);
	free(all->plr->wall_dist_array);
	if (all->mlx->screenshot == 0 && all->file->save == 1)
		make_screenshot(all);
	else
		mlx_put_image_to_window(all->mlx->mlx, all->mlx->win,
			all->mlx->img, 0, 0);
	return (0);
}
