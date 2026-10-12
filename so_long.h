/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:16:01 by daparici          #+#    #+#             */
/*   Updated: 2026/10/12 23:41:38 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE 47
# define STEP_MS 30
#define ENEMY_STEP_MS		50
#define LAST_ENEMY_STAGE	6

# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
#include <sys/time.h>
//# include <xlocale.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
//# include <mlx.h>
# include "./mlx_linux/mlx.h"
# include "./Libft/libft.h"
# include "./GetNextLine/get_next_line.h"
# include "./printf/ft_printf.h"

typedef struct s_map
{
	void			*mlx;
	void			*mlx_window;
	char			**split_map;
	int				n_row;
	int				n_col;
	int				n_exit;
	int				n_pl;
	int				n_enemies;
	int				copy_n_enemies;
	int				enemies_copy;
	int				frames_enemies;
	int				enemy_x;
	int				enemy_y;
	int				copy_enemy_x;
	int				copy_enemy_y;
	int				enemy_dir_y;
	int				enemy_dir_x;
	int				move_enemy_y;
	int				move_enemy_x;
	int				px;
	int				py;
	int				copy_px;
	int				copy_py;
	int				pl_dir;
	int				keycode_c;
	int				ki;
	int				supergoku;
	int				n_collect;
	int				frame_exit;
	int				exit_open;
	int				e_x;
	int				e_y;
	int				n_moves;
	unsigned long	n_frames;
	int				width;
	int				height;
	int				moves;

  	struct timeval 	last_update_time;  // Tiempo de la última actualización
    long long 		time_since_last_change;  // Tiempo transcurrido desde el último cambio de sprite
	
	long long	move_start;
	long long	move_start_enemy;
	int			move_stage;
	int			move_stage_enemy;
	long long	last_enemies;
	long long	last_exit;
}				t_map;

int		error_msg(char *msg);
void	check_map(int argc, char **argv, t_map *map);
void	check_map_name(char **argv);
void	check_map_params(int fd, t_map *map);
void	ft_read_map(int fd, t_map *map, char **map_str);
void	ft_count_params(t_map *map, int i, int k);
int		check_map_error(t_map *map);
t_map	ft_initmap(void);
void	start_game(t_map *map);
int		put_imagen_map(t_map *map);
void	put_walls(t_map *map, int i, int k);
void	put_other_map(t_map *map, int i, int k);
void	get_type_params(t_map map, int i, int k);
void	put_imagen_xpm(t_map *map, char *adress_img, int x, int y);
t_map	*params_init(t_map *map);
t_map	*params_init_2(t_map *map);
int		closewin(t_map *map);
int		render_next_frame(t_map *map);
int		key_select(int keycode, t_map *map);
void	key_y(int keycode, t_map *map);
//void	key_y_2(int keycode, t_map *map);
void	key_x(int keycode, t_map *map);
void	key_x_left(int keycode, t_map *map);
void	key_x_left_2(t_map *map);
void	key_x_right(int keycode, t_map *map);
void	key_x_right_2(t_map *map);
void	put_goku_map(t_map *map);
void	move_goku_y(t_map *map);
void	move_goku_y2(t_map *map);
void	move_goku_x(t_map *map);
void	move_goku_x_right(t_map *map);
void	move_goku_x_left(t_map *map);
void	open_exit(t_map *map);
void	open_exit_2(t_map *map);
void	power_ki(t_map *map);
void	super_power_ki(t_map *map);
void	move_frame(unsigned long frame, t_map *map, char *image);
void	move_frame_2(int stage, t_map *map, char *image);
void	put_goku_map_x(t_map *map);
void	put_goku_map_x2(t_map *map);
void	put_goku_map_y(t_map *map);
void	put_goku_map_y2(t_map *map);
void	move_enemies(t_map *map);
void	move_enemies_2(t_map *map, int i, int k);
void	move_enemy_y(t_map *map);
void	move_enemy_x(t_map *map);
void	move_enemy_frame(int frame, t_map *map, char *image);
void	move_enemy_frame_2(int stage, t_map *map, char *image);
int		move_enemies_identify(t_map *map, int i, int k);
void	move_enemies_params(t_map *map);
void	move_enemy_y_down(t_map *map);
void	move_enemy_y_up(t_map *map);
void	move_enemy_x_right(t_map *map);
void	move_enemy_x_left(t_map *map);
void	print_moves(int moves);

long long get_time_ms();
#endif
