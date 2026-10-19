#include "so_long.h"

static int	count_enemies(t_map *map)
{
	int	i;
	int	k;
	int	n;

	n = 0;
	i = -1;
	while (map->split_map[++i])
	{
		k = -1;
		while (map->split_map[i][++k])
		{
			if (is_enemy(map->split_map[i][k]))
				n++;
		}
	}
	return (n);
}

static void	set_enemy(t_enemy *e, int x, int y)
{
	e->x = x;
	e->y = y;
	e->ox = x;
	e->oy = y;
	e->tx = x;
	e->ty = y;
	e->hx = x;
	e->hy = y;
	e->dx = 0;
	e->dy = 0;
	e->dir_x = 0;
	e->dir = 0;
}

static void	fill_enemies(t_map *map)
{
	int	i;
	int	k;
	int	n;

	n = 0;
	i = -1;
	while (map->split_map[++i])
	{
		k = -1;
		while (map->split_map[i][++k])
		{
			if (is_enemy(map->split_map[i][k]))
			{
				set_enemy(&map->enemies[n], k, i);
				map->enemies[n++].dir = enemy_rand(map) % 4;
			}
		}
	}
}

int	init_enemies(t_map *map)
{
	map->enemies = NULL;
	map->n_enemies = count_enemies(map);
	if (map->n_enemies == 0)
		return (1);
	map->enemies = malloc(sizeof(t_enemy) * map->n_enemies);
	if (!map->enemies)
		return (0);
	map->rng = (unsigned int)get_time_ms();
	fill_enemies(map);
	return (1);
}