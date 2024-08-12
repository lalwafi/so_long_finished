/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:54:24 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/12 15:22:04 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_that_path(char *map_path, t_parsemap **map)
{
	int	fd;

	if (!map_path)
		exit_nicely("wrong map path", 1, map);
	if (ft_strncmp(&map_path[ft_strlen(map_path) - 4], ".ber", 4) != 0 \
		|| ft_strlen(map_path) < 10)
		exit_nicely("needs to be <name>.ber", 1, map);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_nicely("cant open map, doesnt exist?", 1, map);
	ft_printf("map path = %s\nlen = %d\n", map_path, ft_strlen(map_path));
}

void	count_y(char *map_path, t_parsemap **map)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit_nicely("map is empty :(", 1, map);
	while (line)
	{
		if (line[0] == '\n')
			(*map)->empty_line = 1;
		if (line[0] != '\n' && (*map)->empty_line == 1)
		{
			(free(line), close(fd));
			exit_nicely("empty line found in map, fix it pls thanks", 1, map);
		}
		if (line[0] != '\n' && (*map)->empty_line != 1)
			(*map)->y_count += 1;
		free(line);
		line = get_next_line(fd);
	}
	(close(fd), free(line));
}

void	count_x(char *map_path, t_parsemap **map, int i)
{
	int		count;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	count = i;
	(*map)->x_count = i;
	while (line)
	{
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
			i++;
		if (i != count)
		{
			(free(line), close(fd));
			exit_nicely("rows need to be same size", 1, map);
		}
		free(line);
		line = get_next_line(fd);
	}
	(free(line), close(fd));
}
