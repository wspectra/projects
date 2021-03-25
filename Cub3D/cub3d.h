#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

# define SPEED 0.05
# define TURN 0.05

typedef struct	s_sprite
{
	double		pos_x;
	double		pos_y;
	double		dist;
	double		comp_x;
	double		comp_y;
	double		inv_det;
	double		new_x;
	double		new_y;
	int			screen_x;
	int			hight;
	int			width;
	int			draw_start_y;
	int			draw_start_x;
	int			draw_end_y;
	int			draw_end_x;
	int			tex_x;
	int			tex_y;
	int			d;
}				t_sprite;

typedef struct	s_plr
{
	double		pos_x;
	double		pos_y;
	int			map_pos_x;
	int			map_pos_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		vector_x;
	double		vector_y;
	double		plan_x;
	double		plan_y;
	double		side_x;
	double		side_y;
	double		delta_x;
	double		delta_y;
	double		wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			hit;
	int			start_line;
	int			end_line;
	int			hight_line;
	int			wid;
	int			hig;
	double		*wall_dist_array;
}				t_plr;

typedef struct	s_img
{
	void		*img;
	void		*addr;
	int			img_width;
	int			img_height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_pixel
{
	int			x;
	int			y;
	double		wall;
	double		step;
	double		pos;

}				t_pixel;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**map;
	t_img		*north;
	t_img		*west;
	t_img		*south;
	t_img		*east;
	t_img		*sprite;
	t_pixel		*pixel;
	t_sprite	*sprt;
	int			screenshot;
}				t_mlx;

typedef struct	s_file
{
	int			resol_x;
	int			resol_y;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	int			ceilling;
	int			floor;
	int			error;
	char		**map;
	int			sp_num;
	int			save;
	int			plr;
}				t_file;

typedef struct	s_all
{
	t_file		*file;
	t_mlx		*mlx;
	t_plr		*plr;
}				t_all;

void			read_file(int fd, int save);
void			parsing (char **file, int save);
void			print_map(t_all *all);
void			make_cub(t_all *all);
void			check_colors_validity(t_file *file, char *str, int i, char c);
void			check_resolution_validity(t_file *file, char *str, int i);
void			check_path_validity(t_file *file, char *str, int i);
void			check_map_validity(t_all *all, int *start_map,
							int size_file, char **file);
int				check_cell(char **map, int x, int y);
int				check_diag(char **map, int x, int y, int size);
void			delete_file(char **file);
void			delete_structure_file(t_all *all);
void			make_game(t_all *all);
int				ft_make_image(t_all *all);
void			what_pixel(t_img *img, t_all *all, int hig, t_pixel *pixel);
void			make_sprite(t_all *all);
void			make_screenshot(t_all *all);
void			make_file_structure(t_all *all);
void			delete_lsts(t_list **lst);
void			delete_mlx_struct(t_all *all);
void			make_mlx_struct(t_all *all);
void			sprite_struct_init(t_all *all);
void			make_images(t_all *all);
void			xpm_to_image(void *mlx, t_img *img, char *path);
int				press_key(int key, void *all);
int				ft_close(t_all *all);
void			draw_textures(t_all *all, int j, int hig);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void			draw_floor_ceil(t_all *all, int width, int high);
void			sorting_sprite(t_all *all);

#endif
