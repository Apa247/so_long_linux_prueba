#include "so_long.h"

void	move_enemy_x_right(t_map *map, t_enemy *e)
{
	char	next;

	next = map->split_map[e->y][e->x + 1];
	if (next == 'P')
		closewin(map);
	if (!enemy_blocked(next))
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", e->y, e->x);
		e->x++;
		e->dir_x = 0;
		map->split_map[e->y][e->x] = map->split_map[e->y][e->x - 1];
		map->split_map[e->y][e->x - 1] = '0';
		move_enemy_frame_2(map, e, 4, "./sprites/bubu_move_x5.xpm");
	}
	else
	{
		move_enemy_frame_2(map, e, 4, "./sprites/bubu_left.xpm");
		e->dir_x = 1;
	}
}

void	move_enemy_x_left(t_map *map, t_enemy *e)
{
	char	next;

	next = map->split_map[e->y][e->x - 1];
	if (next == 'P')
		closewin(map);
	if (!enemy_blocked(next))
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", e->y, e->x);
		e->x--;
		e->dir_x = 1;
		map->split_map[e->y][e->x] = map->split_map[e->y][e->x + 1];
		map->split_map[e->y][e->x + 1] = '0';
		move_enemy_frame_2(map, e, 4, "./sprites/bubu_move_x5_left.xpm");
	}
	else
	{
		move_enemy_frame_2(map, e, 4, "./sprites/bubu_right.xpm");
		e->dir_x = 0;
	}
}

void	move_enemy_y_up(t_map *map, t_enemy *e)
{
	char	next;

	next = map->split_map[e->y - 1][e->x];
	if (next == 'P')
		closewin(map);
	if (!enemy_blocked(next))
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", e->y, e->x);
		e->y--;
		if (map->px == e->x && map->py == e->y)
			closewin(map);
		if (e->dir_x == 0)
			move_enemy_frame_2(map, e, 5, "./sprites/bubu_right.xpm");
		else
			move_enemy_frame_2(map, e, 5, "./sprites/bubu_left.xpm");
		map->split_map[e->y][e->x] = map->split_map[e->y + 1][e->x];
		map->split_map[e->y + 1][e->x] = '0';
	}
	else
		move_enemy_frame_2(map, e, 5, "./sprites/bubu_right.xpm");
}

void	move_enemy_y_down(t_map *map, t_enemy *e)
{
	char	next;

	next = map->split_map[e->y + 1][e->x];
	if (next == 'P')
		closewin(map);
	if (!enemy_blocked(next))
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", e->y, e->x);
		e->y++;
		if (map->px == e->x && map->py == e->y)
			closewin(map);
		if (e->dir_x == 0)
			move_enemy_frame_2(map, e, 5, "./sprites/bubu_right.xpm");
		else
			move_enemy_frame_2(map, e, 5, "./sprites/bubu_left.xpm");
		map->split_map[e->y][e->x] = map->split_map[e->y - 1][e->x];
		map->split_map[e->y - 1][e->x] = '0';
	}
	else
		move_enemy_frame_2(map, e, 5, "./sprites/bubu_right.xpm");
}