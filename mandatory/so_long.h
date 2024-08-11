/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:51:05 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/11 14:00:09 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft_copy/libft.h"
# include "../ft_printf_copy/ft_printf.h"
# include "../MLX/mlx.h"

# define TILE_SIZE 64
# define PLAYER 'P'
# define COLLECTIBLES 'C'
# define WALL '1'
# define FLOOR '0'
# define EXIT 'E'

typedef struct s_parsemap
{
	int		player;
	int		collectibles;
	int		exit;
	int		x_count;
	int		y_count;
	int		player_y;
	int		player_x;
	int		exit_x;
	int		exit_y;
	int		map_y_axis;
	int		map_x_axis;
	int		empty_line;
	int		temp_collectibles;
	int		temp_exit;
	char	**map_main;
	char	**map_copy;
}	t_parsemap;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*collectible[1];
	void		*exit[1];
	void		*tiles[2];
	void		*player[1];
	int			tile_size;
	int			moves;
	t_parsemap	*map;
}	t_game;

typedef enum keys
{
	W = 13,
	A= 0,
	S = 1,
	D = 2,
	ESC = 53,
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123
}	t_keys;

void	exit_nicely(char *message, int exitnum, t_parsemap **map);
void	do_images_exist(void);
void	parse_that_map(char *map_path, t_game *game);
void	initialize_that_map(t_parsemap **map);
void	validate_that_path(char *map_path, t_parsemap **map);
void	count_y(char *map_path, t_parsemap **map);
void	count_x(char *map_path, t_parsemap **map, int i);
void	get_that_map(char *map_path, t_parsemap **map);
void	check_them_borders(t_parsemap **map);
void	check_elements(t_parsemap **map, int y, int x);
void	save_place(char what, int x, int y, t_parsemap **map);
void	pathfinder_time(t_parsemap **map, int x, int y, char **map_copy);
void	check_epc(t_parsemap **map);
void	time_to_render(t_game *game);
void	initialize_those_pics(t_game *game);
void	render_those_edges(t_game *game, int x, int y);
void	render_inside(t_game *game, int x, int y);
int		hanlde_them_keys(int what_key, t_game *game);
void	move_pls(int new_x, int new_y, t_game *game);
int		game_over(t_game *game, int worl);
void	free_them_sprites(t_game	*game);

#endif