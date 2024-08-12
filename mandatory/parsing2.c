/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:56:07 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/12 15:10:26 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_that_map(char *map_path, t_parsemap **map)
{
	int		i;
	int		count;
	int		fd;
	char	*line;

	(*map)->map_main = (char **)malloc(sizeof(char *) * ((*map)->y_count + 1));
	(*map)->map_copy = (char **)malloc(sizeof(char *) * ((*map)->y_count + 1));
	if (!(*map)->map_copy || !(*map)->map_main)
		exit_nicely("failed malloc for map copies", 1, map);
	i = 0;
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	count = (*map)->y_count;
	while (i < count)
	{
		(*map)->map_main[i] = ft_strdup(line);
		(*map)->map_copy[i] = ft_strdup(line);
		if (!(*map)->map_main[i] || !(*map)->map_copy[i])
			exit_nicely("failed line malloc for map copies", 1, map);
		line = get_next_line(fd);
		i++;
	}
	(*map)->map_main[i] = NULL;
	(*map)->map_copy[i] = NULL;
	(free(line), close(fd));
}

void	check_them_borders(t_parsemap **map)
{
	int	i;

	i = 0;
	while ((*map)->map_copy[0][i] != '\0' &&
			(*map)->map_copy[0][i] != '\n')
	{
		if ((*map)->map_copy[0][i] != WALL)
			exit_nicely("Map should be bordered by walls (1)", 1, map);
		i++;
	}
	i = 0;
	while ((*map)->map_copy[(*map)->y_count - 1][i] != '\n' &&
			(*map)->map_copy[(*map)->y_count - 1][i] != '\0')
	{
		if ((*map)->map_copy[(*map)->y_count - 1][i] != WALL)
			exit_nicely("Map should be bordered by walls (1)", 1, map);
		i++;
	}
	i = (*map)->y_count - 1;
	while (--i > 0)
	{
		if ((*map)->map_copy[i][0] != WALL
			|| (*map)->map_copy[i][(*map)->x_count - 1] != WALL)
			exit_nicely("Map should be bordered by walls (1)", 1, map);
	}
}

void	do_images_exist(void)
{
	static char	*images[5] = {
		"./mandatory/textures/collectible.xpm",
		"./mandatory/tectures/exit",
		"./mandatory/tectures/floor",
		"./mandatory/tectures/player.xpm",
		"./mandatory/tectures/wall"};
	int			fd;
	int			i;
	int			rd;
	char		idk[1];

	fd = 0;
	i = 0;
	rd = 0;
	while (i < 1)
	{
		fd = open(images[i], O_RDONLY);
		if (fd == -1)
			exit_nicely("texture path doesnt exist", 1, NULL);
		rd = read(fd, idk, 1);
		if (rd == -1)
			(close(fd), exit_nicely("texture path doesnt exist", 1, NULL));
		i++;
	}
}
