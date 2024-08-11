/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:34:33 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/11 13:32:01 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	time_to_render(t_game *game)
{
	initialize_those_pics(game);
	render_those_edges(game, 0, 0);
	render_inside(game, 1, 1);
}

void	initialize_those_pics(t_game *game)
{
	game->tile_size = TILE_SIZE;
	game->collectible[0] = mlx_xpm_file_to_image(game->mlx,
			"mandatory/textures/collectible.xpm", (&game->tile_size -8),
			&game->tile_size);
	game->player[0] = mlx_xpm_file_to_image(game->mlx,
			"mandatory/textures/player.xpm", &game->tile_size,
			&game->tile_size);
	game->tiles[0] = mlx_xpm_file_to_image(game->mlx,
			"mandatory/textures/floor.xpm", &game->tile_size,
			&game->tile_size);
	game->tiles[1] = mlx_xpm_file_to_image(game->mlx,
			"mandatory/textures/wall.xpm", &game->tile_size,
			&game->tile_size);
	game->exit[0] = mlx_xpm_file_to_image(game->mlx,
			"mandatory/textures/exit.xpm", &game->tile_size,
			&game->tile_size);
}

void	render_those_edges(t_game *game, int x, int y)
{
	while (y < game->map->y_count)
	{
		while (x < game->map->x_count)
		{
			if (x == 0 || y == 0 || x == (game->map->x_count - 1) \
			|| y == (game->map->y_count - 1))
				mlx_put_image_to_window(game->mlx, game->window,
					game->tiles[1], x * game->tile_size, y * game->tile_size);
			x++;
		}
		x = 0;
		y++;
	}
}

void	render_inside(t_game *game, int x, int y)
{
	while (y < (game->map->y_count - 1))
	{
		while (x < (game->map->x_count - 1))
		{
			if (game->map->map_main[y][x] == WALL)
				mlx_put_image_to_window(game->mlx, game->window,
					game->tiles[1], x * game->tile_size, y * game->tile_size);
			if (game->map->map_main[y][x] == FLOOR)
				mlx_put_image_to_window(game->mlx, game->window,
					game->tiles[0], x * game->tile_size, y * game->tile_size);
			if (game->map->map_main[y][x] == COLLECTIBLES)
				mlx_put_image_to_window(game->mlx, game->window,
					game->collectible[0], x * game->tile_size,
					y * game->tile_size);
			if (game->map->map_main[y][x] == PLAYER)
				mlx_put_image_to_window(game->mlx, game->window,
					game->player[0], x * game->tile_size, y * game->tile_size);
			if (game->map->map_main[y][x] == EXIT)
				mlx_put_image_to_window(game->mlx, game->window,
					game->exit[0], x * game->tile_size, y * game->tile_size);
			x++;
		}
		x = 1;
		y++;
	}
}
