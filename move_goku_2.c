/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_goku_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:35:57 by daparici          #+#    #+#             */
/*   Updated: 2026/10/13 01:18:39 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_goku_map(t_map *map)
{
	if (map->keycode_c == 119 || map->keycode_c == 115)
		put_goku_map_y(map);
	if (map->keycode_c == 97 || map->keycode_c == 100)
		put_goku_map_x(map);
}

void	put_goku_map_x(t_map *map)
{
	if (map->keycode_c == 97 && map->move_stage == 1)
	{
		map->px--;
		if (map->split_map[map->py][map->px] == 'T' || map->split_map[map->py][map->px] == 't')
			closewin(map);
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		if (map->supergoku == 0)
			put_imagen_xpm(map, "./sprites/goku_move_left3.xpm", map->py, map->px);
		else 
			put_imagen_xpm(map, "./sprites/supergoku_move_x2_left.xpm", map->py, map->px);
	}
	if (map->keycode_c == 97 && map->move_stage == 2)
	{
		if (map->supergoku == 0)
			move_frame_2(2, map, "./sprites/goku_left.xpm");
		else
			move_frame_2(2, map, "./sprites/supergoku_left.xpm");
	}
	if (map->keycode_c == 100 && map->move_stage == 1)
	{
		map->px++;
		if (map->split_map[map->py][map->px] == 'T' || map->split_map[map->py][map->px] == 't')
			closewin(map);
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		if (map->supergoku == 0)
			put_imagen_xpm(map, "./sprites/goku_move_left.xpm", map->py, map->px);
		else
			put_imagen_xpm(map, "./sprites/supergoku_move_x2.xpm", map->py, map->px);
	}
	if (map->keycode_c == 100 && map->move_stage == 2)
	{
		if (map->supergoku == 0)
			move_frame_2(2, map, "./sprites/goku_buena.xpm");
		else
			move_frame_2(2, map, "./sprites/supergoku_right.xpm");
	}
}

void	put_goku_map_y(t_map *map)
{
	if (map->keycode_c == 119)
	{
		map->py--;
		if (map->split_map[map->py][map->px] == 'T' || map->split_map[map->py][map->px] == 't')
			closewin(map);
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		if (map->pl_dir == 0)
		{
			if (map->supergoku == 0)
				move_frame_2(3, map, "./sprites/goku_buena.xpm");
			else
				move_frame_2(3, map, "./sprites/supergoku_right.xpm");
		}
		else
		{
			if (map->supergoku == 0)
				move_frame_2(3, map, "./sprites/goku_left.xpm");
			else
				move_frame_2(3, map, "./sprites/supergoku_left.xpm");
		}
	}
	if (map->keycode_c == 115)
	{
		map->py++;
		if (map->split_map[map->py][map->px] == 'T' || map->split_map[map->py][map->px] == 't')
			closewin(map);
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		if (map->pl_dir == 0)
		{
			if (map->supergoku == 0)
				move_frame_2(3, map, "./sprites/goku_buena.xpm");
			else
				move_frame_2(3, map, "./sprites/supergoku_right.xpm");
		}
		else
		{
			if (map->supergoku == 0)
				move_frame_2(3, map, "./sprites/goku_left.xpm");
			else
				move_frame_2(3, map, "./sprites/supergoku_left.xpm");
		}
	}
}

