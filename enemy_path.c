#include "so_long.h"

static int	cell_free(t_map *map, t_bfs *b, int x, int y)
{
	char	c;

	if (x < 0 || y < 0 || x >= b->w || y >= b->h)
		return (0);
	if (x == map->enemy_x && y == map->enemy_y)
		return (1);
	c = map->split_map[y][x];
	return (c != '1' && c != 'C' && c != 'E' && c != 'O');
}

static void	bfs_fill(t_map *map, t_bfs *b)
{
	int	head;
	int	tail;
	int	k;
	int	nx;
	int	ny;

	head = 0;
	tail = 1;
	b->queue[0] = map->py * b->w + map->px;
	b->dist[b->queue[0]] = 0;
	while (head < tail)
	{
		k = -1;
		while (++k < 4)
		{
			nx = b->queue[head] % b->w + (k == 0) - (k == 1);
			ny = b->queue[head] / b->w + (k == 2) - (k == 3);
			if (cell_free(map, b, nx, ny) && b->dist[ny * b->w + nx] == -1)
			{
				b->dist[ny * b->w + nx] = b->dist[b->queue[head]] + 1;
				b->queue[tail++] = ny * b->w + nx;
			}
		}
		head++;
	}
}

static int	step_ok(t_map *map, t_bfs *b, int x, int y)
{
	char	c;

	if (x < 0 || y < 0 || x >= b->w || y >= b->h)
		return (0);
	c = map->split_map[y][x];
	return (b->dist[y * b->w + x] != -1 && c != 'T' && c != 't');
}

static void	best_step(t_map *map, t_bfs *b)
{
	int	k;
	int	nx;
	int	ny;
	int	cur;
	int	best;

	cur = b->dist[map->enemy_y * b->w + map->enemy_x];
	if (cur == -1)
		return ;
	best = cur + 1;
	k = -1;
	while (++k < 4)
	{
		nx = map->enemy_x + (k == 0) - (k == 1);
		ny = map->enemy_y + (k == 2) - (k == 3);
		if (step_ok(map, b, nx, ny)
			&& b->dist[ny * b->w + nx] <= cur
			&& b->dist[ny * b->w + nx] < best)
		{
			best = b->dist[ny * b->w + nx];
			map->copy_px = nx;
			map->copy_py = ny;
		}
	}
}

static int	init_bfs(t_map *map, t_bfs *b)
{
	int	i;

	b->h = 0;
	while (map->split_map[b->h])
		b->h++;
	b->w = ft_strlen(map->split_map[0]);
	b->dist = malloc(sizeof(int) * b->w * b->h);
	b->queue = malloc(sizeof(int) * b->w * b->h);
	if (!b->dist || !b->queue)
	{
		free(b->dist);
		free(b->queue);
		return (0);
	}
	i = -1;
	while (++i < b->w * b->h)
		b->dist[i] = -1;
	return (1);
}

void	set_enemy_target(t_map *map)
{
	t_bfs	b;

	map->copy_enemy_x = map->enemy_x;
	map->copy_enemy_y = map->enemy_y;
	map->copy_px = map->enemy_x;
	map->copy_py = map->enemy_y;
	if (init_bfs(map, &b))
	{
		bfs_fill(map, &b);
		best_step(map, &b);
		free(b.dist);
		free(b.queue);
	}
	map->move_enemy_x = map->copy_enemy_x - map->copy_px;
	if (map->move_enemy_x < 0)
		map->move_enemy_x *= -1;
	map->move_enemy_y = map->copy_enemy_y - map->copy_py;
	if (map->move_enemy_y < 0)
		map->move_enemy_y *= -1;
}