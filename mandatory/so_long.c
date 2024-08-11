/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:50:53 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/11 18:06:55 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_nicely(char *message, int exitnum, t_parsemap **map)
{
	int	i;

	i = -1;
	if ((*map)->map_copy != NULL)
	{
		while ((*map)->map_copy[++i])
			free((*map)->map_copy[i]);
		free((*map)->map_copy);
	}
	i = -1;
	if ((*map)->map_main != NULL)
	{
		while ((*map)->map_main[++i])
			free((*map)->map_main[i]);
		free((*map)->map_main);
	}
	if (message)
		ft_printf("%s", message);
	if (exitnum == 0)
		exit(EXIT_SUCCESS);
	else if (exitnum == 1)
		exit(EXIT_FAILURE);
	else
		ft_printf("exit what???");
}

void	parse_that_map(char *map_path, t_game *game)
{
	int	i;

	i = -1;
	initialize_that_map(&game->map);
	validate_that_path(map_path, &game->map);
	count_y(map_path, &game->map);
	count_x(map_path, &game->map, 0);
	get_that_map(map_path, &game->map);
	if (game->map->x_count > 40 || game->map->y_count > 22)
		exit_nicely("map is too big!! pls fix thanks", 1, &game->map);
	check_them_borders(&game->map);
	check_elements(&game->map, 0, 0);
	check_epc(&game->map);
	pathfinder_time(&game->map, game->map->player_x,
		game->map->player_y, game->map->map_copy);
	if (game->map->temp_collectibles != 0 || game->map->temp_exit != 0)
		exit_nicely("can't collect all C and exit", 1, &game->map);
}

void	initialize_that_map(t_parsemap **map)
{
	(*map)->player = 0;
	(*map)->collectibles = 0;
	(*map)->exit = 0;
	(*map)->x_count = 0;
	(*map)->y_count = 0;
	(*map)->player_y = 0;
	(*map)->player_x = 0;
	(*map)->exit_x = 0;
	(*map)->exit_y = 0;
	(*map)->map_y_axis = 0;
	(*map)->map_x_axis = 0;
	(*map)->empty_line = 0;
	(*map)->temp_collectibles = -1;
	(*map)->temp_exit = -1;
	(*map)->map_copy = NULL;
	(*map)->map_main = NULL;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		exit_nicely("Arguments ain't right, should be \
		'./so_long maps/map<insert number>.ber'", 1, NULL);
	do_images_exist();
	game.map = malloc(sizeof(t_parsemap));
	parse_that_map(av[1], &game);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map->x_count * TILE_SIZE, \
		game.map->y_count * TILE_SIZE, "so_long");
	time_to_render(&game);
	game.moves = 0;
	mlx_hook(game.window, 2, 0, hanlde_them_keys, &game);
	mlx_hook(game.window, 17, 0, game_over, &game);
	mlx_loop(game.mlx);
}
