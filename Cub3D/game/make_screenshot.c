#include "./../cub3d.h"

void	make_header(int wid, int hig, char *data)
{
	*(unsigned short *)data = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(data + 2) = (hig * wid * 3 + 54);
	*(unsigned int *)(data + 6) = 0u;
	*(unsigned char *)(data + 10) = 54;
	*(unsigned int *)(data + 14) = 40;
	*(unsigned int *)(data + 18) = wid;
	*(unsigned int *)(data + 22) = hig;
	*(unsigned short *)(data + 26) = 1;
	*(unsigned short *)(data + 28) = 24;
	*(unsigned int *)(data + 30) = 0;
	*(unsigned int *)(data + 34) = (unsigned int)hig * wid * 3;
	*(int *)(data + 38) = 3780;
	*(int *)(data + 42) = 3780;
	*(int *)(data + 46) = 0;
	*(int *)(data + 50) = 0;
}

void	make_bmp(t_all *all, int fd, int j, int bits_per_pixel)
{
	unsigned int	i;
	char			*data;
	int				x;
	int				y;

	if (!(data = malloc(all->plr->hig * all->plr->wid * 3 + 54)))
		return ;
	i = 0;
	while (i < (unsigned int)(all->plr->hig * all->plr->wid * 3 + 54))
		data[i++] = 0;
	make_header(all->plr->wid, all->plr->hig, data);
	i = 54;
	y = all->plr->hig;
	while (y--)
	{
		x = -1;
		while (++x < all->plr->wid)
		{
			j = (x * (bits_per_pixel / 8)) + (y * all->mlx->line_length);
			*(data + i++) = *(all->mlx->addr + j++);
			*(data + i++) = *(all->mlx->addr + j++);
			*(data + i++) = *(all->mlx->addr + j);
		}
	}
	write(fd, data, all->plr->hig * all->plr->wid * 3 + 54);
}

void	make_screenshot(t_all *all)
{
	int fd;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	make_bmp(all, fd, 0, all->mlx->bits_per_pixel);
	close(fd);
	all->mlx->screenshot = 1;
}
