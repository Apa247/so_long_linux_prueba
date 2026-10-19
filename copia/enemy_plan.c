#include "so_long.h"

int	enemy_reserved(t_map *map, t_enemy *e, int x, int y)
{
	int	j;

	j = -1;
	while (++j < map->n_enemies)
	{
		if (&map->enemies[j] != e
			&& map->enemies[j].tx == x && map->enemies[j].ty == y)
			return (1);
	}
	return (0);
}

static int	step_ok(t_map *map, t_bfs *b, t_enemy *e, int xy[2])
{
	if (xy[0] < 0 || xy[1] < 0 || xy[0] >= b->w || xy[1] >= b->h)
		return (0);
	return (b->dist[xy[1] * b->w + xy[0]] != -1
		&& !is_enemy(map->split_map[xy[1]][xy[0]])
		&& !enemy_reserved(map, e, xy[0], xy[1]));
}

void	enemy_best_step(t_map *map, t_bfs *b, t_enemy *e)
{
	int	k;
	int	xy[2];
	int	cur;
	int	best;

	cur = b->dist[e->y * b->w + e->x];
	if (cur == -1)
		return ;
	best = cur + 1;
	k = -1;
	while (++k < 4)
	{
		xy[0] = e->x + (k == 0) - (k == 1);
		xy[1] = e->y + (k == 2) - (k == 3);
		if (step_ok(map, b, e, xy)
			&& b->dist[xy[1] * b->w + xy[0]] < best)
		{
			best = b->dist[xy[1] * b->w + xy[0]];
			e->tx = xy[0];
			e->ty = xy[1];
		}
	}
}

static void	reset_enemies(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->n_enemies)
	{
		map->enemies[i].ox = map->enemies[i].x;
		map->enemies[i].oy = map->enemies[i].y;
		map->enemies[i].tx = map->enemies[i].x;
		map->enemies[i].ty = map->enemies[i].y;
		map->enemies[i].dx = 0;
		map->enemies[i].dy = 0;
	}
}

void	plan_enemies(t_map *map)
{
	t_bfs	b;
	int		i;

	reset_enemies(map);
	if (!init_bfs(map, &b))
		return ;
	bfs_fill(map, &b, map->px, map->py);
	i = -1;
	while (++i < map->n_enemies)
		enemy_decide(map, &b, &map->enemies[i]);
	free(b.dist);
	free(b.queue);
}