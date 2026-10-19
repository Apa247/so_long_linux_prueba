#include "so_long.h"

static int	wander_ok(t_map *map, t_enemy *e, int k)
{
	int	x;
	int	y;

	x = e->x + (k == 0) - (k == 1);
	y = e->y + (k == 2) - (k == 3);
	return (!enemy_blocked(map->split_map[y][x])
		&& !enemy_reserved(map, e, x, y)
		&& enemy_home_dist(e, x, y) <= WANDER_ZONE);
}

static int	count_dirs(t_map *map, t_enemy *e)
{
	int	k;
	int	n;

	n = 0;
	k = -1;
	while (++k < 4)
	{
		if (k != (e->dir ^ 1) && wander_ok(map, e, k))
			n++;
	}
	return (n);
}

static int	nth_dir(t_map *map, t_enemy *e, int nth)
{
	int	k;

	k = -1;
	while (++k < 4)
	{
		if (k != (e->dir ^ 1) && wander_ok(map, e, k))
		{
			if (nth == 0)
				return (k);
			nth--;
		}
	}
	return (e->dir ^ 1);
}

void	enemy_wander(t_map *map, t_enemy *e)
{
	int	n;
	int	k;

	n = count_dirs(map, e);
	if (n == 0)
		k = e->dir ^ 1;
	else if (wander_ok(map, e, e->dir) && enemy_rand(map) % 4 != 0)
		k = e->dir;
	else
		k = nth_dir(map, e, enemy_rand(map) % n);
	if (!wander_ok(map, e, k))
		return ;
	e->tx = e->x + (k == 0) - (k == 1);
	e->ty = e->y + (k == 2) - (k == 3);
}