#include <stdio.h>
#include "mlx.h"

typedef struct s_img
{
	void			*img;
	unsigned int	*addr;
	int				line;
	int				w;
	int				h;
}	t_img;

static int	load_img(void *mlx, t_img *i, char *path)
{
	int	bpp;
	int	line;
	int	endian;

	i->img = mlx_xpm_file_to_image(mlx, path, &i->w, &i->h);
	if (!i->img)
		return (0);
	i->addr = (unsigned int *)mlx_get_data_addr(i->img, &bpp, &line, &endian);
	i->line = line / 4;
	return (1);
}

static void	copy_sprite(t_img *dst, t_img *src, int px, int py)
{
	int				x;
	int				y;
	unsigned int	c;

	y = 0;
	while (y < src->h)
	{
		x = 0;
		while (x < src->w)
		{
			c = src->addr[y * src->line + x];
			if (!(c >> 24))
				dst->addr[(py + y) * dst->line + px + x] = c;
			x++;
		}
		y++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_img	floor;
	t_img	sprite;
	t_img	frame;
	int		bpp;
	int		line;
	int		endian;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 140, 90, "prueba2");
	if (!load_img(mlx, &floor, "./sprites/suelo_ok.xpm")
		|| !load_img(mlx, &sprite, "./sprites/coleccionable.xpm"))
		return (printf("ERROR: no se pudo cargar un sprite\n"), 1);
	frame.img = mlx_new_image(mlx, 47, 47);
	frame.addr = (unsigned int *)mlx_get_data_addr(frame.img, &bpp, &line,
			&endian);
	frame.line = line / 4;
	frame.w = 47;
	frame.h = 47;
	copy_sprite(&frame, &floor, 0, 0);
	copy_sprite(&frame, &sprite, 0, 0);
	mlx_put_image_to_window(mlx, win, frame.img, 10, 10);
	mlx_put_image_to_window(mlx, win, floor.img, 80, 10);
	mlx_put_image_to_window(mlx, win, sprite.img, 80, 10);
	mlx_string_put(mlx, win, 10, 75, 0xFFFFFF, "nuevo");
	mlx_string_put(mlx, win, 80, 75, 0xFFFFFF, "actual");
	mlx_loop(mlx);
	return (0);
}