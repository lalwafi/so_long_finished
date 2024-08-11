/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:25:24 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/02 23:02:05 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_save(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(sizeof(char) * (ft_strlen_for_gnl(buffer) - i));
	if (!new_buffer)
		return (NULL);
	while (buffer[++i])
		new_buffer[j++] = buffer[i];
	new_buffer[j] = 0;
	free(buffer);
	return (new_buffer);
}

char	*ft_thing_to_print(char *buffer)
{
	char	*thing_to_print;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	thing_to_print = malloc(sizeof(char) * (i + 1 + (buffer[i] == '\n')));
	if (!thing_to_print)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		thing_to_print[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		thing_to_print[i++] = '\n';
	thing_to_print[i] = '\0';
	return (thing_to_print);
}

char	*ft_read_it(char *buffer, int fd)
{
	int		read_return;
	char	*line;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	read_return = 1;
	while (read_return != 0 && ft_strchr_for_gnl(buffer, '\n') == 0)
	{
		read_return = read(fd, line, BUFFER_SIZE);
		if (read_return == -1)
		{
			if (buffer != NULL)
				free(buffer);
			free(line);
			return (NULL);
		}
		line[read_return] = '\0';
		buffer = ft_strjoin_for_gnl(buffer, line);
		if (!buffer)
			break ;
	}
	if (line)
		free(line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*thing_to_print;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buffer[fd] = ft_read_it(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	thing_to_print = ft_thing_to_print(buffer[fd]);
	buffer[fd] = ft_save(buffer[fd]);
	return (thing_to_print);
}
