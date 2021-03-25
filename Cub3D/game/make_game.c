#include "./../cub3d.h"

void	player_pos(t_all *all, int x, int y)
{
	if (all->file->map[y][x] == 'N')
	{
		all->plr->map_pos_x = x;
		all->plr->map_pos_y = y;
		all->plr->pos_x = x + 0.5;
		all->plr->pos_y = y + 0.5;
		all->plr->vector_x = 0;
		all->plr->vector_y = -1;
		all->plr->plan_x = -0.66;
		all->plr->plan_y = 0;
		return ;
	}
	if (all->file->map[y][x] == 'S')
	{
		all->plr->map_pos_x = x;
		all->plr->map_pos_y = y;
		all->plr->pos_x = x + 0.5;
		all->plr->pos_y = y + 0.5;
		all->plr->vector_x = 0;
		all->plr->vector_y = 1;
		all->plr->plan_x = 0.66;
		all->plr->plan_y = 0;
		return ;
	}
}

void	player_pos_2(t_all *all, int x, int y)
{
	if (all->file->map[y][x] == 'W')
	{
		all->plr->map_pos_x = x;
		all->plr->map_pos_y = y;
		all->plr->pos_x = x + 0.5;
		all->plr->pos_y = y + 0.5;
		all->plr->vector_x = -1;
		all->plr->vector_y = 0;
		all->plr->plan_x = 0;
		all->plr->plan_y = 0.66;
		return ;
	}
	else if (all->file->map[y][x] == 'E')
	{
		all->plr->map_pos_x = x;
		all->plr->map_pos_y = y;
		all->plr->pos_x = x + 0.5;
		all->plr->pos_y = y + 0.5;
		all->plr->vector_x = 1;
		all->plr->vector_y = 0;
		all->plr->plan_x = 0;
		all->plr->plan_y = -0.66;
		return ;
	}
}

void	where_is_player(t_all *all)
{
	int x;
	int y;

	y = 0;
	while (all->file->map[y] != NULL)
	{
		x = 0;
		while (all->file->map[y][x] != 'N' && all->file->map[y][x] != 'S' &&
		all->file->map[y][x] != 'W' &&
			all->file->map[y][x] != 'E' && all->file->map[y][x] != '\0')
		{
			x++;
			if (all->file->map[y][x] == 'N' || all->file->map[y][x] == 'S')
			{
				player_pos(all, x, y);
				return ;
			}
			else if (all->file->map[y][x] == 'W' || all->file->map[y][x] == 'E')
			{
				player_pos_2(all, x, y);
				return ;
			}
		}
		y++;
	}
}

void	check_resol(t_all *all)
{
	mlx_get_screen_size(all->mlx->mlx, &all->plr->wid, &all->plr->hig);
	if (all->file->resol_x < all->plr->wid ||
			all->file->resol_y < all->plr->hig)
	{
		all->plr->wid = all->file->resol_x;
		all->plr->hig = all->file->resol_y;
	}
	while (all->file->save == 1 &&
			(all->plr->wid * all->plr->hig) % 16 != 0)
	{
		if (all->plr->wid > 32)
			all->plr->wid--;
		else
			all->plr->wid++;
	}
}

void	make_game(t_all *all)
{
	make_mlx_struct(all);
	sprite_struct_init(all);
	where_is_player(all);
	all->mlx->screenshot = 0;
	all->mlx->mlx = mlx_init();
	make_images(all);
	check_resol(all);
	if (all->file->save == 0)
		all->mlx->win = mlx_new_window(all->mlx->mlx, all->plr->wid,
			all->plr->hig, "Cub3D");
	ft_make_image(all);
	if (all->file->save == 0)
	{
		mlx_hook(all->mlx->win, 2, 0, press_key, all);
		mlx_hook(all->mlx->win, 17, 0, ft_close, all);
		mlx_loop(all->mlx->mlx);
		delete_mlx_struct(all);
	}
}
