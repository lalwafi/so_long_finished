/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:56:30 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/14 19:10:02 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_elements(t_parsemap **map, int y, int x)
{
	y = (*map)->y_count - 1;
	while (y-- > 0)
	{
		while (x < (*map)->x_count)
		{
			if ((*map)->map_copy[y][x] == COLLECTIBLES)
				(*map)->collectibles += 1;
			else if ((*map)->map_copy[y][x] == PLAYER && (*map)->player != 1)
				save_place('P', x, y, map);
			else if ((*map)->map_copy[y][x] == PLAYER && (*map)->player == 1)
				exit_nicely("more than 1 player??", 1, map);
			else if ((*map)->map_copy[y][x] == EXIT && (*map)->exit != 1)
				save_place('E', x, y, map);
			else if ((*map)->map_copy[y][x] == EXIT && (*map)->exit == 1)
				exit_nicely("more than 1 exit??", 1, map);
			else if ((*map)->map_copy[y][x] != WALL
					&& (*map)->map_copy[y][x] != FLOOR)
				exit_nicely("Unknown element in map bro", 1, map);
			x++;
		}
		x = 0;
	}
}

void	save_place(char what, int x, int y, t_parsemap **map)
{
	if (what == 'P')
	{
		(*map)->player += 1;
		(*map)->player_x = x;
		(*map)->player_y = y;
	}
	if (what == 'E')
	{
		(*map)->exit += 1;
		(*map)->exit_x = x;
		(*map)->exit_y = y;
	}
}

void	check_epc(t_parsemap **map)
{
	if ((*map)->player_x == 0 || (*map)->player_y == 0 || (*map)->player == 0)
		exit_nicely("wheres player??????", 1, map);
	if ((*map)->exit_x == 0 || (*map)->exit_y == 0 || (*map)->exit == 0)
		exit_nicely("wheres exit??????", 1, map);
	if ((*map)->collectibles == 0)
		exit_nicely("wheres collectibles??????", 1, map);
}

void	pathfinder_time(t_parsemap **map, int x, int y, char **map_copy)
{
	if ((*map)->temp_collectibles == -1 || (*map)->temp_exit == -1)
	{
		(*map)->temp_collectibles = (*map)->collectibles;
		(*map)->temp_exit = (*map)->exit;
	}
	if (map_copy[y][x] == WALL || (*map)->x_count < x ||
		(*map)->y_count < y || x < 0 || y < 0)
		return ;
	if (map_copy[y][x] == EXIT)
	{
		(*map)->temp_exit -= 1;
		map_copy[y][x] = WALL;
		return ; 
	}
	if (map_copy[y][x] == COLLECTIBLES)
		(*map)->temp_collectibles -= 1;
	map_copy[y][x] = WALL;
	pathfinder_time(map, (x + 1), y, map_copy);
	pathfinder_time(map, (x - 1), y, map_copy);
	pathfinder_time(map, x, (y + 1), map_copy);
	pathfinder_time(map, x, (y - 1), map_copy);
}
