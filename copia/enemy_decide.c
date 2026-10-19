#include "so_long.h"

void	enemy_go_home(t_map *map, t_enemy *e)
{
	t_bfs	b;

	if (!init_bfs(map, &b))
		return ;
	bfs_fill(map, &b, e->hx, e->hy);
	enemy_best_step(map, &b, e);
	free(b.dist);
	free(b.queue);
}

static void	finish_plan(t_enemy *e)
{
	e->dx = (e->tx != e->x);
	e->dy = (e->ty != e->y);
	if (e->tx > e->x)
		e->dir = 0;
	else if (e->tx < e->x)
		e->dir = 1;
	else if (e->ty > e->y)
		e->dir = 2;
	else if (e->ty < e->y)
		e->dir = 3;
}

void	enemy_decide(t_map *map, t_bfs *b, t_enemy *e)
{
	int	d;

	d = b->dist[e->y * b->w + e->x];
	if (d != -1 && d <= AGGRO_RADIUS)
		enemy_best_step(map, b, e);
	else if (enemy_home_dist(e, e->x, e->y) > WANDER_ZONE)
		enemy_go_home(map, e);
	else
		enemy_wander(map, e);
	finish_plan(e);
}