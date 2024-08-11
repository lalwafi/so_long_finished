/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:54:24 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/11 10:09:37 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_that_path(char *map_path, t_parsemap **map)
{
	int	fd;

	if (!map_path)
		(free(*map), exit_nicely("idk what issue this is", 1));
	if (ft_strncmp(&map_path[ft_strlen(map_path) - 4], ".ber", 4) != 0)
		(exit_nicely("needs to be .ber", 1), free(*map));
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		(exit_nicely("cant open map, doesnt exist?", 1), free(*map));
}

void	count_y(char *map_path, t_parsemap **map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i++;
		if (line[0] == '\n')
			(*map)->empty_line = 1;
		if (line[0] != '\n' && (*map)->empty_line == 1)
		{
			(free(line), close(fd), free(*map));
			exit_nicely("empty line found in map, fix it pls thanks", 1);
		}
		if (line[0] != '\n' && (*map)->empty_line != 1)
			(*map)->y_count += 1;
		i = 0;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
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
			(free(line), close(fd), free(*map));
			exit_nicely("rows need to be same size", 1);
		}
		free(line);
		line = get_next_line(fd);
	}
	(free(line), close(fd));
}
