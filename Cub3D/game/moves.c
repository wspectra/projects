#include "./../cub3d.h"

int		ft_close(t_all *all)
{
	mlx_destroy_window(all->mlx->mlx, all->mlx->win);
	free(all->mlx->mlx);
	exit(0);
}

void	ft_move_up_down(t_all *all, double c)
{
	if (all->file->map[(int)(all->plr->pos_y + c * all->plr->vector_y * SPEED)]
		[(int)all->plr->pos_x] != '1')
		all->plr->pos_y += all->plr->vector_y * c * SPEED;
	if (all->file->map[(int)(all->plr->pos_y)]
		[(int)(all->plr->pos_x + c * all->plr->vector_x * SPEED)] != '1')
		all->plr->pos_x += all->plr->vector_x * c * SPEED;
}

void	ft_move_left_right(t_all *all, double c)
{
	if (all->file->map[(int)(all->plr->pos_y - c * all->plr->vector_x * SPEED)]
		[(int)all->plr->pos_x] != '1')
		all->plr->pos_y -= all->plr->vector_x * c * SPEED;
	if (all->file->map[(int)(all->plr->pos_y)]
		[(int)(all->plr->pos_x + c * all->plr->vector_y * SPEED)] != '1')
		all->plr->pos_x += all->plr->vector_y * c * SPEED;
}

void	ft_move_rotate(t_all *all, double c)
{
	double old_x;
	double old_plane;

	old_x = all->plr->vector_x;
	all->plr->vector_x = all->plr->vector_x * cos(c * TURN)
		- all->plr->vector_y * sin(c * TURN);
	all->plr->vector_y = old_x * sin(c * TURN) + all->plr->vector_y *
			cos(c * TURN);
	old_plane = all->plr->plan_x;
	all->plr->plan_x = all->plr->plan_x * cos(c * TURN) - all->plr->plan_y *
			sin(c * TURN);
	all->plr->plan_y = old_plane * sin(c * TURN) +
			all->plr->plan_y * cos(c * TURN);
}

int		press_key(int key, void *all)
{
	t_all *new;

	new = (t_all*)all;
	mlx_destroy_image(new->mlx->mlx, new->mlx->img);
	if (key == 13)
		ft_move_up_down(all, 1);
	else if (key == 1)
		ft_move_up_down(all, -1);
	else if (key == 0)
		ft_move_left_right(all, -1);
	else if (key == 2)
		ft_move_left_right(all, 1);
	else if (key == 123)
		ft_move_rotate(all, 1);
	else if (key == 124)
		ft_move_rotate(all, -1);
	else if (key == 53)
		ft_close(all);
	if (ft_make_image(all) != 1)
		return (-10);
	return (1);
}
