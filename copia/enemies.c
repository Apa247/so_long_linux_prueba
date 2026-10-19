#include "so_long.h"

void	end_enemy_cycle(t_map *map)
{
	map->move_start_enemy = get_time_ms() + ENEMY_REST_MS;
	map->move_stage_enemy = -1;
}

void	move_enemy_frame_2(t_map *map, t_enemy *e, int stage, char *image)
{
	if (map->move_stage_enemy == stage)
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", e->y, e->x);
		put_imagen_xpm(map, image, e->y, e->x);
	}
}

static void	enemy_idle(t_map *map, t_enemy *e)
{
	if (e->dir_x == 0)
		move_enemy_frame_2(map, e, 0, "./sprites/bubu_right.xpm");
	else
		move_enemy_frame_2(map, e, 0, "./sprites/bubu_left.xpm");
}

static void	run_enemy(t_map *map, t_enemy *e)
{
	if (e->dx == 0 && e->dy == 0)
	{
		enemy_idle(map, e);
		return ;
	}
	if (e->dy >= e->dx)
		move_enemy_y(map, e);
	else
		move_enemy_x(map, e);
}

void	move_enemies(t_map *map)
{
	int	target;
	int	i;

	if ((map->enemies_paused && map->move_stage_enemy == -1) || (map->ki == 1 && map->n_collect == 0))
	{
		map->move_start_enemy = get_time_ms();
		return ;
	}
	if (get_time_ms() < map->move_start_enemy)
		return ;
	target = (get_time_ms() - map->move_start_enemy) / ENEMY_STEP_MS;
	if (target <= map->move_stage_enemy)
		return ;
	map->move_stage_enemy++;
	if (map->move_stage_enemy == 0)
		plan_enemies(map);
	i = -1;
	while (++i < map->n_enemies)
		run_enemy(map, &map->enemies[i]);
	if (map->move_stage_enemy >= LAST_ENEMY_STAGE)
		end_enemy_cycle(map);
}