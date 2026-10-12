/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:17:28 by daparici          #+#    #+#             */
/*   Updated: 2026/10/12 22:09:03 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILE 47
#define FLOOR_PATH "./sprites/suelo_ok.xpm"

long long get_time_ms() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int	render_next_frame(t_map *map)
{
	if (map->n_enemies != 0)
		move_enemies(map);
	if ((map->keycode_c == 119 || map->keycode_c == 115))
		move_goku_y(map);
	if (map->keycode_c == 97 || map->keycode_c == 100)
		move_goku_x(map);
	if (map->n_collect == 0 && map->n_exit != 0)
		open_exit(map);
	if (map->ki == 1)
		power_ki(map);
	if (map->ki == 1 && map->n_collect == 0)
		super_power_ki(map);
	map->frame_exit++;
	map->n_frames++;
	map->frames_enemies++;
	if (map->px == map->enemy_x
		&& map->py == map->enemy_y)
		closewin(map);
	return (1);
}

void	start_game(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_window = mlx_new_window(map->mlx, (map->n_col * SIZE) + 2, \
		(map->n_row * SIZE) + 2, "So_long");
	put_imagen_map(map);
	mlx_hook(map->mlx_window, 17, 1L << 17, closewin, map);
	mlx_key_hook(map->mlx_window, key_select, map);
	mlx_loop_hook(map->mlx, render_next_frame, map);
	mlx_string_put(map->mlx, map->mlx_window, 10, 24, 0, "Mv:");
	mlx_string_put(map->mlx, map->mlx_window, 50, 24, 0, "0");

    // Inicializar el temporizador
    //gettimeofday(&map->last_update_time, NULL);
    //map->time_since_last_change = 0;

	mlx_loop(map->mlx);
}

int	key_select(int keycode, t_map *map)
{
	int		i;
	char	*moves;

	i = 0;
	if (keycode == 65307)
	{
		ft_printf("finished!\n");
		exit(0);
		return (1);
	}
	if ((map->move_stage > 3 || map->move_stage == -1) && map->ki == 0)
	{
		if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		{
			key_y(keycode, map);
			key_x(keycode, map);
		}
	}
	moves = ft_itoa(map->moves);
	//put_imagen_xpm(map, "./sprites/lado_up.xpm", 0, 1);
	//put_imagen_xpm(map, "./sprites/lado_up.xpm", 0, 2);
	mlx_string_put(map->mlx, map->mlx_window, 50, 24, 0, moves);
	free(moves);
	return (i);
}

static unsigned int	*get_pixels(void *img, int *line)
{
	int	info[2];

	*line = 0;
	return ((unsigned int *)mlx_get_data_addr(img, &info[0], line, &info[1]));
}

static void	fill_transparent(void *sprite, void *floor)
{
	unsigned int	*s;
	unsigned int	*f;
	int				ls;
	int				lf;
	int				i;

	s = get_pixels(sprite, &ls);
	f = get_pixels(floor, &lf);
	ls /= 4;
	lf /= 4;
	i = 0;
	while (i < TILE * TILE)
	{
		if (s[(i / TILE) * ls + i % TILE] >> 24)
			s[(i / TILE) * ls + i % TILE] = f[(i / TILE) * lf + i % TILE];
		i++;
	}
}

void	put_imagen_xpm(t_map *map, char *adress_img, int x, int y)
{
	void	*img;
	void	*floor;
	int		res;

	res = TILE;
	map->width = (TILE * y);
	map->height = (TILE * x);
	img = mlx_xpm_file_to_image(map->mlx, adress_img, &res, &res);
	floor = mlx_xpm_file_to_image(map->mlx, FLOOR_PATH, &res, &res);
	if (!img || !floor)
	{
		ft_printf("ERROR\n");
		exit(1);
	}
	fill_transparent(img, floor);
	mlx_put_image_to_window(map->mlx, map->mlx_window, img,
		map->width, map->height);
	mlx_destroy_image(map->mlx, floor);
	mlx_destroy_image(map->mlx, img);
}

