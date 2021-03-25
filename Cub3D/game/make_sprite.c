#include "./../cub3d.h"

void	sprite_new_position(t_mlx *mlx, t_plr *plr, int i)
{
	mlx->sprt[i].inv_det = 1.0 / (plr->plan_x *
		plr->vector_y - plr->vector_x * plr->plan_y);
	mlx->sprt[i].new_x = mlx->sprt[i].inv_det * (plr->vector_y *
			mlx->sprt[i].comp_x - plr->vector_x * mlx->sprt[i].comp_y);
	mlx->sprt[i].new_y = mlx->sprt[i].inv_det * (-plr->plan_y *
			mlx->sprt[i].comp_x + plr->plan_x * mlx->sprt[i].comp_y);
	mlx->sprt[i].screen_x = (int)(plr->wid / 2)
			* (1 + mlx->sprt[i].new_x / mlx->sprt[i].new_y);
	mlx->sprt[i].hight = abs((int)(plr->hig / (mlx->sprt[i].new_y)));
	mlx->sprt[i].draw_start_y = -mlx->sprt[i].hight / 2 + plr->hig / 2;
	if (mlx->sprt[i].draw_start_y < 0)
		mlx->sprt[i].draw_start_y = 0;
	mlx->sprt[i].draw_end_y = mlx->sprt[i].hight / 2 + plr->hig / 2;
	if (mlx->sprt[i].draw_end_y >= plr->hig)
		mlx->sprt[i].draw_end_y = plr->hig - 1;
	mlx->sprt[i].width = abs((int)(plr->wid / mlx->sprt[i].new_y));
	mlx->sprt[i].draw_start_x = -mlx->sprt[i].width / 2 + mlx->sprt[i].screen_x;
	if (mlx->sprt[i].draw_start_x < 0)
		mlx->sprt[i].draw_start_x = 0;
	mlx->sprt[i].draw_end_x = mlx->sprt[i].width / 2 + mlx->sprt[i].screen_x;
	if (mlx->sprt[i].draw_end_x >= plr->wid)
		mlx->sprt[i].draw_end_x = plr->wid - 1;
}

void	draw_sprite(int i, int start, t_mlx *mlx, t_plr *plr)
{
	int j;
	int color;
	int *dst;

	if (mlx->sprt[i].new_y > 0 && start > 0 && start < plr->wid &&
	mlx->sprt[i].new_y < plr->wall_dist_array[start] && mlx->sprt[i].dist
	> 0.09)
	{
		j = mlx->sprt[i].draw_start_y;
		while (j < mlx->sprt[i].draw_end_y)
		{
			mlx->sprt[i].d = j * 256
				- plr->hig * 128 + mlx->sprt[i].hight * 128;
			mlx->sprt[i].tex_y = ((mlx->sprt[i].d * mlx->sprite->img_height)
					/ mlx->sprt[i].hight) / 256;
			dst = (void *)mlx->sprite->addr + (mlx->sprt[i].tex_y *
					mlx->sprite->line_length + mlx->sprt[i].tex_x *
					(mlx->sprite->bits_per_pixel / 8));
			color = *(int*)dst;
			if ((color & 0x00ffffff) != 0)
				my_mlx_pixel_put(mlx, start, j, color);
			j++;
		}
	}
}

void	sprite_calculations(t_all *all)
{
	int i;
	int start;

	i = 0;
	while (i < all->file->sp_num)
	{
		sprite_new_position(all->mlx, all->plr, i);
		start = all->mlx->sprt[i].draw_start_x;
		while (start < all->mlx->sprt[i].draw_end_x)
		{
			all->mlx->sprt[i].tex_x = (int)(256 * (start -
					(-all->mlx->sprt[i].width / 2 +
					all->mlx->sprt[i].screen_x)) * all->mlx->sprite->img_width
							/ all->mlx->sprt[i].width) / 256;
			draw_sprite(i, start, all->mlx, all->plr);
			start++;
		}
		i++;
	}
}

void	make_sprite(t_all *all)
{
	int i;

	i = 0;
	while (i < all->file->sp_num)
	{
		all->mlx->sprt[i].dist = (all->plr->pos_x - all->mlx->sprt[i].pos_x) *
				(all->plr->pos_x - all->mlx->sprt[i].pos_x) +
				(all->plr->pos_y - all->mlx->sprt[i].pos_y) *
				(all->plr->pos_y - all->mlx->sprt[i].pos_y);
		all->mlx->sprt[i].comp_x = all->mlx->sprt[i].pos_x - all->plr->pos_x;
		all->mlx->sprt[i].comp_y = all->mlx->sprt[i].pos_y - all->plr->pos_y;
		i++;
	}
	sorting_sprite(all);
	sprite_calculations(all);
}
