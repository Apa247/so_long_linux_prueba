/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_goku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:35:57 by daparici          #+#    #+#             */
/*   Updated: 2026/10/12 21:59:35 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_goku_x(t_map *map)
{
	int	stage;

	stage = (get_time_ms() - map->move_start) / STEP_MS;
	if (stage == map->move_stage)
		return ;
	map->move_stage = stage;
	printf("Move Stage: %d\n", map->move_stage);
	if (map->keycode_c == 97)
		move_goku_x_left(map);
	if (map->keycode_c == 100)
		move_goku_x_right(map);
}


void	move_goku_x_right(t_map *map)
{
	if (map->move_stage == 0)
	{
		if (map->supergoku == 0)
			move_frame_2(0, map, "./sprites/goku_move_right.xpm");
		else
			move_frame_2(0, map, "./sprites/supergoku_move_x.xpm");
	}
	else if (map->move_stage == 1)
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", map->py, map->px);
		map->split_map[map->py][map->px] = '0';
		put_goku_map(map);
	}
	else if (map->move_stage == 2)
		put_goku_map(map);
}

void	move_goku_x_left(t_map *map)
{
	if (map->move_stage == 0)
	{
		if (map->supergoku == 0)
			move_frame_2(0, map, "./sprites/goku_move_y_left2.xpm");
		else
			move_frame_2(0, map, "./sprites/supergoku_move_x_left.xpm");
	}
	else if (map->move_stage == 1)
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", map->py, map->px);
		map->split_map[map->py][map->px] = '0';
		put_goku_map(map);
	}
	else if (map->move_stage == 2)
		put_goku_map(map);
}

void	move_goku_y(t_map *map)
{
	int	stage;

	stage = (get_time_ms() - map->move_start) / STEP_MS;
	if (stage == map->move_stage)
		return ;
	map->move_stage = stage;
	printf("Move Stage: %d\n", map->move_stage);
	if (map->move_stage == 0)
	{
		if (map->pl_dir == 0)
		{
			if (map->supergoku == 0)
				put_imagen_xpm(map, "./sprites/goku_move_y.xpm", map->py, map->px);
			else
				put_imagen_xpm(map, "./sprites/supergoku_move_y.xpm", map->py, map->px);
		}
		else
		{
			if (map->supergoku == 0)
				put_imagen_xpm(map, "./sprites/goku_move_y_left.xpm", map->py, map->px);
			else
				put_imagen_xpm(map, "./sprites/supergoku_move_y_left.xpm", map->py, map->px);
		}
	}
	else if (map->move_stage == 1)
	{
		if (map->pl_dir == 0)
		{
			if (map->supergoku == 0)
				put_imagen_xpm(map, "./sprites/goku_move_y_borroso.xpm", map->py, map->px);
			else
				put_imagen_xpm(map, "./sprites/supergoku_move_y2.xpm", map->py, map->px);
		}
		else
		{
			if (map->supergoku == 0)
				put_imagen_xpm(map, "./sprites/goku_move_y_borroso2.xpm", map->py, map->px);
			else
				put_imagen_xpm(map, "./sprites/supergoku_move_y2_left.xpm", map->py, map->px);
		}
	}
	else if (map->move_stage == 2)
		move_frame_2(2, map, "./sprites/goku_move_y_bueno.xpm");
	else if (map->move_stage == 3)
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", map->py, map->px);
		map->split_map[map->py][map->px] = '0';
		put_goku_map(map);
	}
}


/*
void	move_goku_x_right(t_map *map)
{
	if (map->n_frames == 100)
	{
		if (map->supergoku == 0)
			move_frame(100, map, "./sprites/goku_move_right.xpm");
		else
			move_frame(100, map, "./sprites/supergoku_move_x.xpm");
	}
	if (map->n_frames == 800)
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", map->py, map->px);
		map->split_map[map->py][map->px] = '0';
		put_goku_map(map);
	}
	if (map->n_frames == 1300)
		put_goku_map(map);
}

void	move_goku_x_left(t_map *map)
{
	if (map->n_frames == 0)
	{
		if (map->supergoku == 0)
			move_frame(0, map, "./sprites/goku_move_y_left2.xpm");
		else
			move_frame(0, map, "./sprites/supergoku_move_x_left.xpm");
	}
	if (map->n_frames == 800)
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", map->py, map->px);
		map->split_map[map->py][map->px] = '0';
		put_goku_map(map);
	}
	if (map->n_frames == 1300)
		put_goku_map(map);
}

void	move_goku_y(t_map *map)
{

	int	stage;

	stage = (get_time_ms() - map->move_start) / STEP_MS;
	if (stage == map->move_stage)
		return ;
	map->move_stage = stage;
	if (map->n_frames == 0)
	{
		if (map->pl_dir == 0)
		{
			if (map->supergoku == 0)
				put_imagen_xpm(map, "./sprites/goku_move_y.xpm", map->py, map->px);
			else
				put_imagen_xpm(map, "./sprites/supergoku_move_y.xpm", map->py, map->px);
		}
		else
			if (map->supergoku == 0)
				put_imagen_xpm(map, "./sprites/goku_move_y_left.xpm", map->py, map->px);
			else
				put_imagen_xpm(map, "./sprites/supergoku_move_y_left.xpm", map->py, map->px);
	}
	if (map->n_frames == 400)
	{
		if (map->pl_dir == 0)
		{
			if (map->supergoku == 0)
				put_imagen_xpm(map, "./sprites/goku_move_y_borroso.xpm", map->py, map->px);
			else
				put_imagen_xpm(map, "./sprites/supergoku_move_y2.xpm", map->py, map->px);
		}
		else
		{
			if (map->supergoku == 0)
				put_imagen_xpm(map, "./sprites/goku_move_y_borroso2.xpm", map->py, map->px);
			else
				put_imagen_xpm(map, "./sprites/supergoku_move_y2_left.xpm", map->py, map->px);
		}
	}
	move_frame(800, map, "./sprites/goku_move_y_bueno.xpm");
	if (map->n_frames == 1200)
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", map->py, map->px);
		map->split_map[map->py][map->px] = '0';
		put_goku_map(map);
	}
}

*/



