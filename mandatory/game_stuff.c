/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 00:32:52 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/11 18:05:49 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// why int????
int	hanlde_them_keys(int what_key, t_game *game)
{
	if (what_key == ESC)
		game_over(game, 0);
	if (what_key == W || what_key == UP)
		move_pls(game->map->player_x, game->map->player_y - 1, game);
	if (what_key == A || what_key == LEFT)
		move_pls(game->map->player_x - 1, game->map->player_y, game);
	if (what_key == S || what_key == DOWN)
		move_pls(game->map->player_x, game->map->player_y + 1, game);
	if (what_key == D || what_key == RIGHT)
		move_pls(game->map->player_x + 1, game->map->player_y, game);
	return (0);
}

void	move_pls(int new_x, int new_y, t_game *game)
{
	if (game->map->map_main[new_y][new_x] == WALL)
		return ;
	if (game->map->map_main[new_y][new_x] == EXIT &&
			game->map->collectibles > 0)
		return ;
	game->moves += 1;
	ft_printf("moves = %d\n", game->moves);
	if (game->map->map_main[new_y][new_x] == EXIT &&
			game->map->collectibles <= 0)
		game_over(game, 1);
	if (game->map->map_main[new_y][new_x] == COLLECTIBLES)
	{
		game->map->collectibles -= 1;
		game->map->map_main[new_y][new_x] = '0';
	}
	mlx_put_image_to_window(game->mlx, game->window,
		game->tiles[0], game->map->player_x * game->tile_size,
		game->map->player_y * game->tile_size);
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	mlx_put_image_to_window(game->mlx, game->window,
		game->player[0], game->map->player_x * game->tile_size,
		game->map->player_y * game->tile_size);
}

int	game_over(t_game *game, int WorL)
{
	int	i;

	i = 0;
	free_them_sprites(game);
	mlx_destroy_window(game->mlx, game->window);
	if (WorL == 1)
		exit_nicely("!!!!YOU WIN!!!!", 0, &game->map);
	else
		exit_nicely("Game closed", 0, &game->map);
	return (0);
}

void	free_them_sprites(t_game	*game)
{
	mlx_destroy_image(game->mlx, game->collectible[0]);
	mlx_destroy_image(game->mlx, game->exit[0]);
	mlx_destroy_image(game->mlx, game->tiles[0]);
	mlx_destroy_image(game->mlx, game->tiles[1]);
	mlx_destroy_image(game->mlx, game->player[0]);
}
