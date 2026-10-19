#include "so_long.h"

void	move_enemy_x(t_map *map, t_enemy *e)
{
	if (e->tx > e->ox)
	{
		move_enemy_frame_2(map, e, 0, "./sprites/bubu_move_x.xpm");
		move_enemy_frame_2(map, e, 1, "./sprites/bubu_move_x2.xpm");
		move_enemy_frame_2(map, e, 2, "./sprites/bubu_move_x3.xpm");
		move_enemy_frame_2(map, e, 3, "./sprites/bubu_move_x4.xpm");
		if (map->move_stage_enemy == 4)
			move_enemy_x_right(map, e);
		move_enemy_frame_2(map, e, 5, "./sprites/bubu_move_x2.xpm");
		move_enemy_frame_2(map, e, 6, "./sprites/bubu_right.xpm");
	}
	else if (e->tx < e->ox)
	{
		move_enemy_frame_2(map, e, 0, "./sprites/bubu_move_x_left.xpm");
		move_enemy_frame_2(map, e, 1, "./sprites/bubu_move_x2_left.xpm");
		move_enemy_frame_2(map, e, 2, "./sprites/bubu_move_x3_left.xpm");
		move_enemy_frame_2(map, e, 3, "./sprites/bubu_move_x4_left.xpm");
		if (map->move_stage_enemy == 4)
			move_enemy_x_left(map, e);
		move_enemy_frame_2(map, e, 5, "./sprites/bubu_move_x2_left.xpm");
		move_enemy_frame_2(map, e, 6, "./sprites/bubu_left.xpm");
	}
}

void	move_enemy_y(t_map *map, t_enemy *e)
{
	move_enemy_frame_2(map, e, 0, "./sprites/bubu_right2.xpm");
	move_enemy_frame_2(map, e, 1, "./sprites/bubu_move_y.xpm");
	move_enemy_frame_2(map, e, 2, "./sprites/bubu_move_y2.xpm");
	move_enemy_frame_2(map, e, 3, "./sprites/bubu_move_y3.xpm");
	move_enemy_frame_2(map, e, 4, "./sprites/bubu_move_y4.xpm");
	if (map->move_stage_enemy == 5 && e->ty < e->oy)
		move_enemy_y_up(map, e);
	if (map->move_stage_enemy == 5 && e->ty > e->oy)
		move_enemy_y_down(map, e);
}