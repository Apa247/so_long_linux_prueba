#include "so_long.h"

static int	cell_free(t_map *map, t_bfs *b, int x, int y)
{
	char	c;

	if (x < 0 || y < 0 || x >= b->w || y >= b->h)
		return (0);
	c = map->split_map[y][x];
	return (c != '1' && c != 'C' && c != 'E' && c != 'O');
}

void	bfs_fill(t_map *map, t_bfs *b, int sx, int sy)
{
	int	head;
	int	tail;
	int	k;
	int	nx;
	int	ny;

	head = 0;
	tail = 1;
	b->queue[0] = sy * b->w + sx;
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

int	init_bfs(t_map *map, t_bfs *b)
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