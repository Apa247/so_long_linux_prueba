#include "so_long.h"

int	is_enemy(char c)
{
	return (c == 'T' || c == 't');
}

int	enemy_blocked(char c)
{
	return (c == '1' || c == 'C' || c == 'E' || c == 'O' || is_enemy(c));
}

int	enemy_hit(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->n_enemies)
	{
		if (map->px == map->enemies[i].x && map->py == map->enemies[i].y)
			return (1);
	}
	return (0);
}

int	enemy_home_dist(t_enemy *e, int x, int y)
{
	int	dx;
	int	dy;

	dx = x - e->hx;
	dy = y - e->hy;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	return (dx + dy);
}

unsigned int	enemy_rand(t_map *map)
{
	map->rng = map->rng * 1103515245 + 12345;
	return ((map->rng >> 16) & 0x7fff);
}